#include <bits/stdc++.h>

using namespace std;

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
		vector<T> res (total);
		for (int i = 0; i < total; i++) {
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
	if (min ((int) A.size(),(int) B.size()) <= 250) {
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
	
	return 0;
}
