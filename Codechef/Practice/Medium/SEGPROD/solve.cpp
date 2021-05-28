#include <bits/stdc++.h>

using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* ch) { return string(ch); }
string to_string(char ch) { return (string)"'" + ch + (string)"'"; }
string to_string(bool b) { return (b ? "true" : "false"); }
template<class A, class B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<class A>
string to_string(A a) {
	string res = "{";
	bool first = true;
	for(const auto& x: a) { if(first == false) res += ", "; first = false, res += to_string(x); }
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

template<class X, class Y, class Z = int64_t> X bpow (X a , Y b, int mod = -1) {
	X res = static_cast<X> (1);
	if (mod != -1 && (a < -mod || a >= mod)) { 
		a %= mod; 
	}
	while(b) {
		if(b % 2 == 1) {
			if (mod != -1) {
				// (res *= a) %= mod;
				Z tmp = static_cast<Z> (1) * res * a;
				if (tmp < -mod || tmp >= mod) tmp %= mod;
				res = static_cast<X> (tmp);
			}
			else res *= a;
		}
		if (mod != -1) {
			// (a *= a) %= mod;
			Z tmp = static_cast<Z> (1) * a * a;
			if (tmp < -mod || tmp >= mod) tmp %= mod;
			a = static_cast<X> (tmp);
		}
		else a *= a;
		b /= 2;
	}
	return res;
}

template<typename X> class mod {
public:
	using T = typename decay<decltype(X::value)>::type;

	template<typename U>
	T normalize(const U& x) {
		T y;
		if (x < -MOD() || x >= MOD()) y = static_cast<T> (x % MOD());
		else y =  static_cast<T> (x);
		if (y < 0) y += MOD();
		return y;
	}

	mod () : value(0) {}
	template<typename U> mod (const U& x) : value(normalize(x)) {}
	constexpr static T MOD () { return X::value; }

	const T& operator ()() const { return value; }
	template<typename U> mod<U> inverse (const mod<U>& x) { 
		return mod<U> (bpow <typename decay<decltype(U::value)>::type, typename decay<decltype(U::value)>::type> (x.value, U::value - 2, U::value)); 
	}

	template <typename U> friend ostream& operator << (ostream& out, const mod<U>& x) { out << x.value; return out; }
	template <typename U> friend istream& operator >> (istream& in, mod<U>& x) { typename decay<decltype(U::value)>::type tmp; in >> tmp; x = mod<U> (tmp); return in; }
	mod& operator += (const mod& x) { if ((value += x.value) >= MOD()) value -= MOD(); return *this; }
	mod& operator -= (const mod& x) { if ((value -= x.value) < 0) value += MOD(); return *this; }
	mod& operator *= (const mod& x) { value = normalize (static_cast <int64_t> (value) * static_cast <int64_t> (x.value)); return *this; }
	mod& operator /= (const mod& x) { return *this *= inverse(x); }
	template <typename U> mod& operator += (const U& x) { return *this += mod (x); }
	template <typename U> mod& operator -= (const U& x) { return *this -= mod (x); }
	template <typename U> mod& operator *= (const U& x) { return *this *= mod (x); }
	template <typename U> mod& operator /= (const U& x) { return *this /= mod (x); }
	template <typename U> mod& operator %= (const U& x) { value %= x; return *this; }
	mod& operator ++ () { return *this += 1; }
	mod& operator -- () { return *this -= 1; }
	mod  operator ++ (int) { mod res(value); *this += 1; return res; }
	mod  operator -- (int) { mod res(value); *this -= 1; return res; }
	mod  operator -  () const { return mod(-value); }
	mod  operator +  () const { return *this; }
	template <typename U> friend bool operator == (const mod<U>& a, const mod<U>& b) { return a.value == b.value; }
	template <typename U, typename V> friend bool operator == (V a, const mod<U>& b) { return mod<U> (a) == b; }
	template <typename U, typename V> friend bool operator == (const mod<U>& a, V b) { return a == mod<U> (b); }
	template <typename U> friend bool operator != (const mod<U>& a, const mod<U>& b) { return a.value != b.value; }
	template <typename U, typename V> friend bool operator != (V a, const mod<U>& b) { return mod<U> (a) != b; }
	template <typename U, typename V> friend bool operator != (const mod<U>& a, V b) { return a != mod<U> (b); }
	template <typename U> friend mod<U> operator + (const mod<U>& a, const mod<U>& b) { return mod(a) += b; }
	template <typename U, typename V> friend mod<U> operator + (V a, const mod<U>& b) { return mod(a) += b; }
	template <typename U, typename V> friend mod<U> operator + (const mod<U>& a, V b) { return mod(a) += b; }
	template <typename U> friend mod<U> operator - (const mod<U>& a, const mod<U>& b) { return mod(a) -= b; }
	template <typename U, typename V> friend mod<U> operator - (V a, const mod<U>& b) { return mod(a) -= b; }
	template <typename U, typename V> friend mod<U> operator - (const mod<U>& a, V b) { return mod(a) -= b; }
	template <typename U> friend mod<U> operator * (const mod<U>& a, const mod<U>& b) { return mod(a) *= b; }
	template <typename U, typename V> friend mod<U> operator * (V a, const mod<U>& b) { return mod(a) *= b; }
	template <typename U, typename V> friend mod<U> operator * (const mod<U>& a, V b) { return mod(a) *= b; }
	template <typename U> friend mod<U> operator / (const mod<U>& a, const mod<U>& b) { return mod(a) /= b; }
	template <typename U, typename V> friend mod<U> operator / (V a, const mod<U>& b) { return mod(a) /= b; }
	template <typename U, typename V> friend mod<U> operator / (const mod<U>& a, V b) { return mod(a) /= b; }
	template <typename U> friend string to_string (const mod<U>& x) { return to_string(x.value); }
	template <typename U, typename V> friend mod<U> bpow (mod<U> a, V b) {
		return mod<U> (bpow <typename decay<decltype(U::value)>::type, V> (a.value, b, U::value));
	}
private:
	T value;
};

using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mod = mod <VarMod>;

// constexpr int md = 998244353;
// using Mod = mod <std::integral_constant<typename decay<decltype(md)>::type, md>>;

// vector<Mod> fact(2, 1), inv_fact(2, 1), inv(2, 1);

// Mod nCr (int n, int r) {
// 	if (r > n) return 0;
// 	while ((int)fact.size() <= n) {
// 		fact.push_back (fact.back() * static_cast<int> (fact.size()));
// 		inv.push_back (md - (md / (int)inv.size()) * inv[md % (int(inv.size()))]);	// commnent this if no of calls for nCr is low
// 		inv_fact.push_back (inv_fact.back() * inv[inv_fact.size()]); // commnent this if no of calls for nCr is low
// 	}
// 	return fact[n] * inv_fact[n - r] * inv_fact[r];	// commnent this if no of calls for nCr is low
// 	// return fact[n] / (fact[n - r] * fact[r]);	// uncommnent this if no of calls for nCr is low
// }

template <typename T, typename F = function <T (const T&, const T&)>>
class DisjointSparseTable {
protected:
	int k;
	vector<vector<T>> dst;
	F func;
public:
	DisjointSparseTable (vector<T> a, const F& f) : func(f) {
		k = 32 - __builtin_clz (static_cast <int> (a.size()));
		const int n = 1 << k;
		a.resize(n);
		dst.assign (k, vector<T> (n));
		build (a);
	}

	void build (const vector<T>& a) {
		const int n = a.size();
		assert ((n & (n - 1)) == 0);
		assert ((1 << k) == n);
		for (int height = 0; height < k; height++) {
			for (int node = 0; node < (1 << height); node++) {
				int L = node * (n >> height);
				int R = L + (n >> height);
				int M = (L + R) / 2;
				dst[height][M] = a[M];
				for (int idx = M + 1; idx < R; idx++) {
					dst[height][idx] = func (dst[height][idx - 1], a[idx]);
				}
				assert (M > 0);
				dst[height][M - 1] = a[M - 1]; // might overflow here
				for (int idx = M - 2; idx >= L; idx--) {
					dst[height][idx] = func (dst[height][idx + 1], a[idx]);
				}
			}
		}
	}
};


template <typename T, typename F = function <T (const T&, const T&)>>
class RangeQuery : public DisjointSparseTable <T, F> {
public:
	RangeQuery (vector<T> a, const F& f) : DisjointSparseTable <T, F> (a, f) {}
	T get (const int& L, const int& R) {
		if (L == R) {
			return DisjointSparseTable<T, F>::dst.back()[L];
		}
		assert (L < R);
		const int height = DisjointSparseTable<T, F>::k - (31 - __builtin_clz (L ^ R)) - 1;
		return DisjointSparseTable<T, F>::func (DisjointSparseTable<T, F>::dst[height][L], DisjointSparseTable<T, F>::dst[height][R]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> md >> q;
		vector<Mod> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> b ((q / 64) + 2);
		for (int i = 0; i < int(b.size()); i++) {
			cin >> b[i];
		}
		RangeQuery <Mod> rq (a, [] (Mod x, Mod y) -> Mod { return x * y; });
		Mod prev_ans = 0;
		pair<int, int> range;
		for (int i = 0; i < q; i++) {
			if (i % 64 == 0) {
				range.first = b[i / 64] + prev_ans();
				range.second = b[(i / 64) + 1] + prev_ans();
			} else {
				range.first += prev_ans();
				range.second += prev_ans();
			}
			range.first %= n;
			range.second %= n;
			if (range.first > range.second) { swap (range.first, range.second); }
			// auto [l, r] = range;
			int l = range.first, r = range.second;
			// l--, r--;
			debug (l, r);
			prev_ans = rq.get (l, r) + 1;
		}
		cout << prev_ans << '\n';
	}	
	return 0;
}
