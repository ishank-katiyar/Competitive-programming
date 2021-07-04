#include <bits/stdc++.h>

using namespace std;

namespace Factorisation {

// run classical seive if only is_prime is needed, otherwise run linear_seive
// basic function linear_seive, seive, segmented_seive
// public:- prime, Sieve, LinearSieve, smallest_factor, is_Prime, prime_factors, factors

vector<bool> is_prime;
vector<int> prime;
vector<int> smallest_factor;
vector<int> phi;

void Sieve (const int n) {
	is_prime.assign(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 4; i <= n; i += 2) {
		is_prime[i] = false;
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) prime.push_back(i);
	}
}

void LinearSieve(const int n) {
	smallest_factor.assign(n + 1, 0);
	is_prime.assign(n + 1, false);
	for (int i = 2; i <= n; i++) {
		if (smallest_factor[i] == 0) {
			smallest_factor[i] = i;
			is_prime[i] = true;
			prime.push_back(i);
		}
		for (int j = 0; j < (int) prime.size() && prime[j] <= smallest_factor[i] && i * prime[j] <= n; j++) {
			smallest_factor[i * prime[j]] = prime[j];
		}
	}
}

int64_t binpower(int64_t base, int64_t e, int64_t mod) {
		int64_t result = 1;
		base %= mod;
		while (e) {
				if (e & 1)
						result = (__int128)result * base % mod;
				base = (__int128)base * base % mod;
				e >>= 1;
		}
		return result;
}

bool check_composite(int64_t n, int64_t a, int64_t d, int s) {
		int64_t x = binpower(a, d, n);
		if (x == 1 || x == n - 1)
				return false;
		for (int r = 1; r < s; r++) {
				x = (__int128)x * x % n;
				if (x == n - 1)
						return false;
		}
		return true;
}

bool MillerRabin(int64_t n) { // returns true if n is prime, else returns false.
		if (n < 2)
				return false;

		int r = 0;
		int64_t d = n - 1;
		while ((d & 1) == 0) {
				d >>= 1;
				r++;
		}

		for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
				if (n == a * int64_t(1))
						return true;
				if (check_composite(n, a, d, r))
						return false;
		}
		return true;
}

template<class X> bool is_Prime (const X n) { return n < (int) is_prime.size() ? is_prime[n] : MillerRabin(n); }

int64_t mult(int64_t a, int64_t b, int64_t mod) {
	a %= mod;
	b %= mod;
	int64_t result = 0;
	while (b) {
		if (b & 1) {
			result = result + a;
			if (result >= mod) {
				result -= mod;
			}
		}
		a <<= 1;
		if (a >= mod) {
			a -= mod;
		}
		b >>= 1;
	}
	return result;
}

int64_t f(int64_t x, int64_t c, int64_t mod) {
	int64_t xx = mult (x, x, mod);
	xx += c;
	if (xx >= mod) {
		xx -= mod;
	}
	return xx;
}

template <class X> X gcd(X a, X b) { return b == 0 ? a : gcd (b, a % b); }

int64_t brent(int64_t n, int64_t x0=2, int64_t c=1) {
	int64_t x = x0;
	int64_t g = 1;
	int64_t q = 1;
	int64_t xs, y;
	int64_t cnt = 0;

	int m = 128;
	int l = 1;
	while (g == 1) {
		y = x;
		for (int i = 1; i < l; i++)
			x = f(x, c, n), cnt += 1;
		int k = 0;
		while (k < l && g == 1) {
			xs = x;
			for (int i = 0; i < m && i < l - k; i++) {
				x = f(x, c, n);
				q = mult(q, abs(y - x), n);
				cnt += 1;
			}
			g = gcd(q, n);
			k += m;
		}
		l *= 2;
	}
	if (g == n) {
		do {
			xs = f(xs, c, n);
			g = gcd(abs(xs - y), n);
			cnt += 1;
		} while (g == 1);
	}
	return g;
}

template<class X>
vector<X> trial_division3 (X n) {
	if (n <= 0) { return {};	}
	vector<X> factorization;
	for (int d : {2, 3, 5}) {
		if (n % d == 0) factorization.push_back (d);
		while (n % d == 0) {
			n /= d;
		}
	}
	static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (X d = 7; d * d <= n; d += increments[i++]) {
		if (n % d == 0) factorization.push_back (d);
		while (n % d == 0) {
			n /= d;
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

template<class X> vector<X> prime_factors (X N) {
	if (N < (int) smallest_factor.size()) {
		vector<X> ret;
		while (N > 1) {
			X pp = smallest_factor[N];
			ret.push_back(pp);
			while (N % pp == 0) N /= pp;
		}
		return ret;
	}
	if (MillerRabin (N)) { return {N}; }
	const int64_t threshold = 1e10;
	if (N <= threshold) { return trial_division3 (N); }
	X pp = brent (N);
	vector<X> ans = prime_factors (pp);
	for (auto& i: ans) {
			while (N % i == 0) N /= i;
	}
	vector<X> aa = prime_factors (N);
	for (auto& i: aa) { ans.push_back (i); }
	return ans;
}

template<class X> vector<X> factors (X n) {
	vector<X> ret;
	for (X i = 1; i * i <= n; i++) {
		if (n % i) continue;
		ret.push_back(i);
		if (n / i != i)	ret.push_back(n / i);
	}
	return ret;
}

void LinearPhi (const int n) {
	phi.assign (n + 1, 0);
	iota(phi.begin(), phi.end(), 0);
	for (int i = 2; i <= n; i++) {
		if (phi[i] != i) continue;
		for (int j = i; j <= n; j += i) {
			phi[j] -= phi[j] / i;
		}
	} 
}

template<class X> X Phi (X n) {
	cerr << "Run LinearSieve if not LinearPhi for faster complexity of Phi(n) ;)" << '\n';
	if (n < (int) phi.size()) { return phi[n]; }
	X ret = n;
	for (auto& i: prime_factors(n)) { ret -= (ret / i); }
	return ret;
}

}; // end namespace factorisation

// using namespace Factorisation;
using Factorisation::prime;		// will be sorted
using Factorisation::is_Prime;	// n <= 1e18
using Factorisation::Sieve;			// n <= 1e7 (46ms), n <= 1e8 (904ms), n <= 1e9 (8626ms) without prime vector
using Factorisation::LinearSieve;	// n == 1e7 (108ms), n == 1e8 (888ms)
using Factorisation::smallest_factor;
using Factorisation::prime_factors;	// n <= 1e18, for (1..n) n <= 1e6 (187ms), for (1..n) n <= 1e7 (1778ms), not sorted
using Factorisation::factors;		// not sorted
using Factorisation::LinearPhi;	// n <= 1e6 (15ms), n <= 1e7 (358ms), n <= 1e8 (4071ms)
using Factorisation::Phi;		// n <= 1e18

template<class X, class Y, class Z = int64_t, typename std::enable_if<std::is_integral<Y>::value>::type* = nullptr> 
X bpow (X a , Y b, int mod = -1) {
	X res = static_cast<X> (1);
	if (mod != -1 && (a < -mod || a >= mod)) a %= mod;
	while(b) {
		if(b % 2 == 1) {
			if (mod != -1) {
				Z tmp = static_cast<Z> (1) * res * a;
				if (tmp < -mod || tmp >= mod) tmp %= mod;
				res = static_cast<X> (tmp);
			}
			else res = res * a;
		}
		if (mod != -1) {
			Z tmp = static_cast<Z> (1) * a * a;
			if (tmp < -mod || tmp >= mod) tmp %= mod;
			a = static_cast<X> (tmp);
		}
		else a = a * a;
		b /= 2;
	}
	return res;
}

template<typename X> class mod {
public:
	using T = typename std::decay<decltype(X::value)>::type;

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
		return mod<U> (bpow <typename std::decay<decltype(U::value)>::type, typename std::decay<decltype(U::value)>::type> (x.value, U::value - 2, U::value)); 
	}

	template <typename U> friend std::ostream& operator << (std::ostream& out, const mod<U>& x) { out << x.value; return out; }
	template <typename U> friend std::istream& operator >> (std::istream& in, mod<U>& x) { typename std::decay<decltype(U::value)>::type tmp; in >> tmp; x = mod<U> (tmp); return in; }
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
	template <typename U> friend std::string to_string (const mod<U>& x) { return to_string(x.value); }
	std::string to_string () const { return std::to_string(value); }
	template <typename U, typename V> friend mod<U> bpow (mod<U> a, V b) {
		return mod<U> (bpow <typename std::decay<decltype(U::value)>::type, V> (a.value, b, U::value));
	}
private:
	T value;
};

// using ModType = int;
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mod = mod <VarMod>;

constexpr int md = 1e9 + 7;
using Mod = mod <std::integral_constant<typename std::decay<decltype(md)>::type, md>>;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};

template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

} // namespace std

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int64_t n;
		cin >> n;
		__int128_t mul = 1;
		Mod ans = 0;
		// int64_t cur = 1;
		// while (mul <= n) {
		for (int64_t cur = 2; cur <= 1000; cur++) {
			mul *= (cur - 1) / __gcd (mul, (__int128_t) (cur - 1));
			if (mul > n) break;
			auto xx = cur /  __gcd ( (__int128_t) cur, mul);
			auto total = n / mul;
			total -= total / xx;
			ans += Mod(cur) * total;
		}
		cout << ans << '\n';
	}
	return 0;
}
