#include <bits/stdc++.h>

using namespace std;

string to_string(string s) 																		{ return '"' + s + '"'; }
string to_string(const char* ch) 															{ return string(ch); }
string to_string(char ch) 																		{ return (string)"'" + ch + (string)"'"; }
string to_string(bool b) 																			{ return (b ? "true" : "false"); }
template<class A, class B> string to_string(pair<A, B> p) 		{ return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
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

template<class X, class Y> X bpow (X a , Y b, int mod = -1) {
	X res(1);
	if (mod != -1) { a %= mod; }
	while(b) {
		if(b % 2 == 1) {
			if (mod != -1) (res *= a) %= mod;
			else res *= a;
		}
		if (mod != -1) (a *= a) %= mod;
		else a *= a;
		b /= 2;
	}
	return res;
}

template<int MOD_> class mod {
	using T = int64_t;
	T value;
	const static T crazy_number = T(3037000499);

public:
	const static int MOD = MOD_;
	static_assert (MOD <= crazy_number);

	T normalize(T x) { 
		if (x < -MOD || x >= MOD) { x %= MOD; }
		if (x < 0) x += MOD;
		return x;
	}

	mod () : value(0) {}
	template<typename U> mod (const U& x) : value(normalize(x)) {}

	const T& operator ()() const { return value; }
	friend mod inverse (const mod& x) { return bpow <mod<MOD>, T> (x, MOD - 2); }

	friend ostream& operator << (ostream& out, const mod& x) { out << x(); return out; }
	friend istream& operator >> (istream& in, mod& x) { int64_t n_; in >> n_; x = mod(n_); return in; }
	friend bool operator == (const mod& a, const mod& b) { return a() == b(); }
	friend bool operator != (const mod& a, const mod& b) { return a() != b(); }
	mod& operator += (const mod& x) { value = normalize (value + x.value); return *this; }
	mod& operator -= (const mod& x) { value = normalize (value - x.value); return *this; }
	mod& operator *= (const mod& x) { value = normalize (value * x.value); return *this; }
	mod& operator /= (const mod& x) { return *this *= inverse(x); }
	template <typename U> mod& operator += (const U& x) { return *this += mod (x); }
	template <typename U> mod& operator -= (const U& x) { return *this -= mod (x); }
	template <typename U> mod& operator *= (const U& x) { return *this *= mod (x); }
	template <typename U> mod& operator /= (const U& x) { return *this /= mod (x); }
	template <typename U> mod& operator %= (const U& x) { value = normalize(value % x); return *this; }
	mod& operator ++ () { return *this += 1; }
	mod& operator -- () { return *this -= 1; }
	mod  operator ++ (int) { mod res(value); *this += 1; return res; }
	mod  operator -- (int) { mod res(value); *this -= 1; return res; }
	mod& operator -  () const { return mod(-value); }
	mod& operator +  () const { return *this; }
	friend mod operator + (const mod& a, const mod& b) { return mod(a) += b; }
	friend mod operator - (const mod& a, const mod& b) { return mod(a) -= b; }
	friend mod operator * (const mod& a, const mod& b) { return mod(a) *= b; }
	friend mod operator / (const mod& a, const mod& b) { return mod(a) /= b; }
	friend string to_string (const mod& x) { return to_string(x.value); }
};

const int md = 998244353;
using Mod = mod <md>;

vector<Mod> fact(2, 1), inv_fact(2, 1), inv(2, 1);

Mod nCr (int n, int r) {
	if (r > n) return 0;
	while ((int)fact.size() <= n) {
		fact.push_back (fact.back() * fact.size());
		inv.push_back (md - (md / (int)inv.size()) * inv[md % (int(inv.size()))]);	// commnent this if no of calls for nCr is low
		inv_fact.push_back (inv_fact.back() * inv[inv_fact.size()]); // commnent this if no of calls for nCr is low
	}
	return fact[n] * inv_fact[n - r] * inv_fact[r];	// commnent this if no of calls for nCr is low
	// return fact[n] / (fact[n - r] * fact[r]);	// uncommnent this if no of calls for nCr is low
}

template<typename T = Mod>
class NTT {
public:
	static int md;
	static T root;
	static int base;
	static int max_base;
	static vector<int> rev;
	static vector<T> roots;

	static void clear() { root = md = base = max_base = 0; rev.clear(), roots.clear(); }

	static void init () {
		md = T::MOD;
		max_base = __builtin_ctz (md - 1);
		debug (max_base);
		root = 2;
		while (bpow (root, (md - 1) / 2) == 1) { root += 1; }
		assert (bpow (root, md - 1) == 1);
		root = bpow (root, (md - 1) >> max_base);
		base = 1;
		rev = {0, 1};
		roots = {0, 1};
	}

	static void ensure_base (int new_base) {
		if (md != T::MOD) { clear(); }
		if (roots.empty() || rev.empty()) { init(); }
		if (base >= new_base) { return; }
		assert (new_base <= max_base);
		rev.resize(1 << new_base);
		for (int i = 0; i < (1 << new_base); i++) { rev[i] = (rev[i / 2] >> 1) | (i % 2) << (new_base - 1); }
		roots.resize(1 << new_base);
		while (base < new_base) {
			const T z = bpow (root, 1 << (max_base - base - 1));
			for (int i = 1 << (base - 1); i < (1 << base); i++) {
				roots[i << 1] = roots[i];
				roots[(i << 1) + 1] = roots[i] * z;
			}
			base++;
		}
	}

	static void ntt (vector<T> &a) {
		int n = a.size();
		int zeros = __builtin_ctz (n);
		ensure_base (zeros);
		int shift = base - zeros;
		for (int i  = 0; i < n; i++) { if (i < (rev[i] >> shift)) swap (a[i], a[rev[i] >> shift]); }
		for (int k = 1; k < n; k *= 2) {
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					auto x = a[i + j], y = a[i + j + k] * roots[j + k];
					a[i + j] = x + y;
					a[i + j + k] = x - y;
				}
			}
		}
	}

	static vector<T> multiply (vector<T> a, vector<T> b) {
		if (a.empty() || b.empty()) return {};
		int total = int (a.size() + b.size()) - 1;
		int n = 1 << (32 - __builtin_clz(total));
		vector<T> A (a), B (b);
		A.resize (n), B.resize (n);
		ntt (A);
		if (b != a) ntt (B); else B = A;
		T inv_n = 1 / T (n);
		for (int i = 0; i < n; i++) { A[i] *= B[i] * inv_n; }
		ntt (A);
		reverse (A.begin() + 1, A.end());
		A.resize (total);
		return A;
	}
};

template <typename T> int NTT <T>::md;
template <typename T> T NTT <T>::root;
template <typename T> int NTT <T>::base;
template <typename T> int NTT <T>::max_base;
template <typename T> vector<int> NTT <T>::rev;
template <typename T> vector<T> NTT <T>::roots;

vector<Mod> operator * (const vector<Mod>& A, const vector<Mod>& B) { 
	if (A.empty() || B.empty()) { return {}; }
	if (min ((int) A.size(),(int) B.size()) <= 250) {
		vector<Mod> C ((int) A.size() + (int) B.size() - 1, 0);
		for (int i = 0; i < (int) A.size(); i++) {
			for (int j = 0; j < (int) B.size(); j++) {
				C[i + j] += A[i] * B[j];
			}
	}
		return C;
	}
	return NTT <Mod> :: multiply (A, B); 
}
vector<Mod> operator *= (vector<Mod>& A, const vector<Mod>& B) { return A = A * B; }

class graph {
public:
	int n;
	vector<vector<int>> adj;
	vector<int> degree;
	vector<pair<int, int>> edge;
	vector<int> depth;
	vector<bool> covered;
	graph (int N): n (N), adj (vector<vector<int>> (n)), degree (vector<int> (n)), depth (vector<int> (n)), covered (vector<bool> (n, false)) {}
	void add (int X, int Y) {
		degree[X]++, degree[Y]++;
		edge.emplace_back(X, Y);
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
	void dfs (int N) {
		if (covered[N] == true) return;
		covered[N] = true;
		for (int i: adj[N]) {
			if (covered[i] == false) {
				depth[i] = depth[N] + 1;
				dfs(i);
			} 
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	while (t.size() < s.size()) t += "z";
	assert (t.size() == s.size());
	vector<graph> gr (n - m + 1, graph(6));
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			vector<Mod> a (n), b (n);
			for (int k = 0; k < n; k++) {
				if (int(s[k] - 'a') == i) a[k] = 1;
				if (int(t[k] - 'a') == j) b[k] = 1;
			}
			// debug (i, j, a, b);
			reverse(a.begin(), a.end());
			for (int k = 0; k < n; k++) a.push_back(0), b.push_back(b[k]);
			a *= b;
			// debug (a);
			for (int k = 2 * n - 1, cnt = 0; cnt < n - m + 1; k--, cnt++) {
				if (a[k]()) {
					debug (i, j, cnt);
					gr[cnt].add (i, j);
				}
			}
		}
	}
	for (int i = 0; i < n - m + 1; i++) {
		int ans = 0;
		debug (i, gr[i].adj);
		for (int j = 0; j < 6; j++) {
			if (gr[i].covered[j] == false) {
				gr[i].dfs (j);
				ans += 1;
			}
		}
		cout << 6 - ans << ' ';
	}
	cout << '\n';
	return 0;
}
