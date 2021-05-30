#include <bits/stdc++.h>

using namespace std;

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

// using ModType = int;
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mod = mod <VarMod>;

constexpr int md = 998244353;
using Mod = mod <std::integral_constant<typename decay<decltype(md)>::type, md>>;

vector<Mod> fact(2, 1), inv_fact(2, 1), inv(2, 1);

Mod nCr (int n, int r) {
	if (r > n) return 0;
	while ((int)fact.size() <= n) {
		fact.push_back (fact.back() * static_cast<int> (fact.size()));
		inv.push_back (md - (md / (int)inv.size()) * inv[md % (int(inv.size()))]);	// commnent this if no of calls for nCr is low
		inv_fact.push_back (inv_fact.back() * inv[inv_fact.size()]); // commnent this if no of calls for nCr is low
	}
	return fact[n] * inv_fact[n - r] * inv_fact[r];	// commnent this if no of calls for nCr is low
	// return fact[n] / (fact[n - r] * fact[r]);	// uncommnent this if no of calls for nCr is low
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
