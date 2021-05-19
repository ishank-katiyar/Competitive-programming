#include <bits/stdc++.h>

using namespace std;

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
// using mod = mod <md>;
#define mod mod<md>

vector<mod> fact(2, 1), inv_fact(2, 1), inv(2, 1);

mod nCr (int n, int r) {
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
	
	return 0;
}
