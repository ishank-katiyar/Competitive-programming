#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

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

template<class X, class Y> X bpow(X a , Y b, int mod = -1) {
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

template<int MOD> class mod {
	using T = int64_t;
	T value;
	const static T crazy_number = T(3037000499);
	static_assert (MOD <= crazy_number);

public:
	T normalize(T x) { 
		if (x < -MOD || x >= MOD) { x %= MOD; }
		if (x < 0) x += MOD;
		return x;
	}

	mod () : value(0) {}
	template<typename U> mod (const U& x) : value(normalize(x)) {}

	const T& operator ()() const { return value; }
	friend mod inverse (const mod& x) { return mod(bpow <T, T> (x.value, MOD - 2, MOD)); }

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

const int md = 1e9 + 7;
using Mod = mod <md>;
// #define mod mod<md>

vector<Mod> fact(2, 1), inv_fact(2, 1), inv(2, 1);

Mod nCr (int n, int r) {
	if (r > n) return 0;
	while ((int)fact.size() <= n) {
		fact.push_back (fact.back() * fact.size());
		inv.push_back (md - (md / (int)inv.size()) * inv[md % (int(inv.size()))]);
		inv_fact.push_back (inv_fact.back() * inv[inv_fact.size()]);
	}
	return fact[n] * inv_fact[n - r] * inv_fact[r];
	// return fact[n] / (fact[n - r] * fact[r]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Mint x(5);
	// cout << x << '\n';
	// x = 100;
	// cout << x << '\n';
	// Mint xx;
	// cin >> xx;
	// cout << xx () << '\n';
	// cout << xx.inverse() << '\n';
	// modu x = 5;
	// x *= 100;
	// cout << x << '\n';
	// cout << to_string (x) << '\n';
	// x = 1e9 + 8;
	// cout << x << '\n';
	// const int maxn = 1e5 + 1;
	// vector<modu> fact (maxn, 1);
	// for (int i = 1; i < maxn; i++) {
	// 	fact[i] = fact[i - 1] * i;
	// }
	// int n, r;
	// cin >> n >> r;
	// cout << nCr (n, r) << '\n';
	const int maxn = 1e7 + 1;
	for (int i = 0; i < maxn; i++) {
		int n = rnd (1, maxn - 1);
		Mod x = nCr (n, rnd (1, n));
		x++;
		++x;
		x--;
		--x;
	}
	return 0;
}
