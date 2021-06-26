#include <bits/stdc++.h>

using namespace std;


string to_string(string s) 																		{ return '"' + s + '"'; }
string to_string(const char* ch) 															{ return string(ch); }
string to_string(char ch) 																		{ return (string)"'" + ch + (string)"'"; }
string to_string(bool b) 																			{ return (b ? "true" : "false"); }
template<class A, class B> string to_string(pair<A, B> p) 		{ return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
string to_string(complex<double> a) { return "(" + to_string (real(a)) + ", " + to_string(imag(a)) + ")"; }
string to_string(vector<complex<double>> a) {
	string res = "{";
	bool first = true;
	int n = a.size();
	for(int i = 0; i < n; i++) {
		auto x = a[i];
		if(first == false) res += ", ";
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}
template<class A> string to_string(A a) {
	string res = "{";
	bool first = true;
	for(const auto& x: a) {
		if(first == false) res += ", ";
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}
void debug() {cerr << "]\n";}
template<class H, class... T> void debug(H head, T... tail) 	{ cerr << to_string(head) << " "; debug(tail...); }

#ifdef LOCAL
	#define debug(...) cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else 
	#define debug(...) 
#endif

template <typename dbl> struct cplx {
	dbl x, y;
	cplx(dbl x_ = 0, dbl y_ = 0) : x(x_), y(y_) { }
	friend cplx operator+(cplx a, cplx b) { return cplx(a.x + b.x, a.y + b.y); }
	friend cplx operator-(cplx a, cplx b) { return cplx(a.x - b.x, a.y - b.y); }
	friend cplx operator*(cplx a, cplx b) { return cplx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
	friend cplx conj(cplx a) { return cplx(a.x, -a.y); }
	friend cplx inv(cplx a) { dbl n = (a.x*a.x+a.y*a.y); return cplx(a.x/n,-a.y/n); }
	friend string to_string (cplx a) { return "(" + to_string(a.x) + ", " + to_string(a.y) + ")"; }
};

using cd = cplx<double>;
const double PI = acos (-1);

class FFT {
public:
	static int base;
	static vector<int> rev;
	static vector<cd> roots;

	static void init() {
		rev = {0, 1};
		roots = vector<cd> (2, 1);
		base = 1;
	}

	static void ensure_base (int new_base) {
		if (roots.empty() || rev.empty()) { init(); }
		if (base >= new_base) { return; }
		rev.resize(1 << new_base);
		for (int i = 0; i < (1 << new_base); i++) { rev[i] = ((rev[i / 2] >> 1) | (i % 2) << (new_base - 1)); }
		roots.resize (1 << new_base);
		while (base < new_base) {
			const auto z1 = polar (1.0, PI / (1 << base));
			const auto z = cd (real (z1), imag (z1));
			for (int i = (1 << (base - 1)); i < (1 << base); i++) {
				roots[i << 1] = roots[i];
				roots[(i << 1) + 1] = roots[i] * z;
			}
			base++;
		}
	}

	static void fft (vector<cd> &a) {
		int n = a.size();
		int zeros = __builtin_ctz (n);
		ensure_base (zeros);
		int shift = base - zeros;
		for (int i = 0; i < n; i++) { if (i < (rev[i] >> shift)) swap (a[i], a[rev[i] >> shift]); }
		for (int k = 1; k < n; k *= 2) { 
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					auto x = a[i + j], y = a[i + j + k] * roots[k + j];
					a[i + j] = x + y;
					a[i + j + k] = x - y;
				}
			}
		}
	}

	template<typename T> 
	static vector<T> multiply (vector<T> a, vector<T> b) {
		if (a.empty() || b.empty()) return {};
		int total = int (a.size() + b.size()) - 1;
		int n = 1 << (32 - __builtin_clz(total));
		debug (total, n);
		// vector<cd> A (a.begin(), a.end()), B (b.begin(), b.end());
		// vector<cd> A (a.begin(), a.end()), B (n);
		// A.resize (n);
		// for (int i = 0; i < int (b.size ()); i++) A[i].imag(b[i]);
		vector<cd> A (n), B (n);
		for (int i = 0; i < n; i++) {
			T x = (i < int(a.size()) ? a[i] : 0);
			T y = (i < int(b.size()) ? b[i] : 0);
			A[i] = cd (x, y);
		}
		fft (A);
		for (auto& i: A) { i = i * i; }
		for (int i = 0; i < n; i++) {
			B[i] = A [(n - i) & (n - 1)] - conj (A[i]);
		}
		fft (B);
		debug (B);
		// if (A != B) fft (B); else B = A;
		// debug (A);
		// debug (B);
		// for (int i = 0; i < n; i++) { A[i] *= B[i] / cd (n); }
		// fft (A);
		// debug (A);
		// reverse (A.begin() + 1, A.end());
		vector<T> res (total);
		for (int i = 0; i < total; i++) {
			// res[i] = round(A[i].real());
			res[i] =  (llround (B[i].y)) / (4 * n);
		}
		return res;
	}

	template <typename T, typename Z = int64_t>
	static vector<T> multiply_mod (vector<T> a, vector<T> b, int m) {
		if (a.empty() || b.empty()) return {};
		int total = int (a.size() + b.size()) - 1;
		int n = 1 << (32 - __builtin_clz(total));
		vector<cd> A (n), B (n);
		for (int i = 0; i < int (a.size()); i++) {
			T x = (a[i] % m + m) % m;
			A[i] = cd (x & ((1 << 15) - 1), x >> 15);
		}
		fft (A);
		if (a == b) B = A;
		else {
			for (int i = 0; i < int (b.size ()); i++) {
				T x = (b[i] % m + m) % m;
					B[i] = cd (x & ((1 << 15) - 1), x >> 15);
			}
			fft (B);
		}
		double ratio = 0.25 / n;
		cd r2(0, -1);
		cd r3(ratio, 0);
		cd r4(0, -ratio);
		cd r5(0, 1);
		for (int i = 0; i <= (n >> 1); i++) {
			int j = (n - i) & (n - 1);
			cd a1 = (A[i] + conj(A[j]));
			cd a2 = (A[i] - conj(A[j])) * r2;
			cd b1 = (B[i] + conj(B[j])) * r3;
			cd b2 = (B[i] - conj(B[j])) * r4;
			if (i != j) {
				cd c1 = (A[j] + conj(A[i]));
				cd c2 = (A[j] - conj(A[i])) * r2;
				cd d1 = (B[j] + conj(B[i])) * r3;
				cd d2 = (B[j] - conj(B[i])) * r4;
				A[i] = c1 * d1 + c2 * d2 * r5;
				B[i] = c1 * d2 + c2 * d1;
			}
			A[j] = a1 * b1 + a2 * b2 * r5;
			B[j] = a1 * b2 + a2 * b1;
		}
		fft(A);
		fft(B);
		vector<T> res(total);
		for (int i = 0; i < total; i++) {
			Z aa = llround(A[i].x), bb = llround(B[i].x), cc = llround(A[i].y);
			res[i] = static_cast<T> ((aa + ((bb % m) << 15) + ((cc % m) << 30)) % m);
		}
		return res;
	}
};

int FFT::base;
vector<int> FFT::rev;
vector<cd> FFT::roots;

template<typename T> vector<T> operator *  (const vector<T>& A, const vector<T>& B) { 
	if (min ((int) A.size(),(int) B.size()) < 0) {
		vector<T> C ((int) A.size() + (int) B.size() - 1);
		for (int i = 0; i < (int) A.size(); i++) {
			for (int j = 0; j < (int) B.size(); j++) {
				C[i + j] += A[i] * B[j];
			}
		}
		return C;
	}
	return FFT::multiply <T> (A, B); 
}
template<typename T> vector<T> operator *= (vector<T>& A, const vector<T>& B) { return A = A * B; }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	vector<int> aa (a.begin(), a.end()), bb (b.begin(), b.end());
	for_each (aa.begin(), aa.end(), [](int &x) -> int {x -= int('0'); return x;});
	for_each (bb.begin(), bb.end(), [](int &x) -> int {x -= int('0'); return x;});
	// reverse (aa.begin(), aa.end());
	// reverse (bb.begin(), bb.end());
	debug (aa, bb);
	aa *= bb;
	debug (aa);
	// reverse(aa.begin(), aa.end());
	int carry = 0;
	for (int i = (int) aa.size() - 1; i >= 0; i--) {
		aa[i] += carry;
		carry = aa[i] / 10;
		aa[i] %= 10;
	}
	aa.front() += carry * 10;
	debug (aa);
	for(auto& i: aa) cout << i;
	cout << '\n';
	// cout << to_string (aa) << '\n';
	return 0;
}
