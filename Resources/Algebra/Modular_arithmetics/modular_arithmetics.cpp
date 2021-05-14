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
	cerr << "Run LinearSieve if not LinearPhi for faster complexity of Phi(n) ;)" << '\n';\
	if (n < (int) phi.size()) { return phi[n]; }
	X ret = n;
	for (auto& i: prime_factors(n)) { ret -= (ret / i); }
	return ret;
}

}; // end namespace factorisation

namespace Modular_Arithmetics {

//----------------------------------------------------------------
// contain basic function like discrete logarithm, primitive root, discrete root
//															  DL()						  generator() 		DR()
//----------------------------------------------------------------

template<class X, class Y> X bpow (X a , Y b, int64_t mod) {	// use like bpow <__int128, int64_t> for mod > 1e9
	X res(1);
	a %= mod;
	while(b) {
		if(b % 2 == 1) { (res *= a) %= mod; }
		(a *= a) %= mod;
		b /= 2;
	}
	return res;
}

template<class X> X generator (X p) {
	X phi = Factorisation::Phi(p);
	vector<X> fact = Factorisation::prime_factors(phi);
	for (X res = 2; res <= p; res++) {
		bool ok = true;
		for (size_t i = 0; i < fact.size() && ok; i++) { ok &= bpow <int64_t, int64_t> (res, phi / fact[i], p) != 1; }
		if (ok) return res;
	}
	return -1;
}

template<class X> X Discrete_Logarithm (X a, X b, X mod, X k1 = 1, X k2 = 1) {	// return -1 if DL doesnt exist, otherwise ans, form := (k1 * a ^ (k2 * x) === b) % mod
	a %= mod, b %= mod;
	X k = 1, add = 0;

	if (X gd = Factorisation::gcd(a, mod); gd > X (1)) {
		if (b == k) { return add; }
		if (b % gd) { return -1; }
		b /= gd, mod /= gd, add += 1;
		(k *= a / gd) %= mod;
	}

	X phi = mod - 1;
	if (Factorisation::is_Prime(mod) == false) phi = Factorisation::Phi(mod);

	X n = sqrt (mod + 0.0) + 1;
	X cur = b;
	X ak2 = bpow <X, X> (a, (k2 % phi) + phi, mod);
	unordered_map<X, X> vals;
	for (X q = 0; q <= n; q++) {
		// X cur = (b * bpow <int64_t, int64_t> (a, (k2 * q) % phi + phi, mod)) % mod;
		vals[cur] = q;
		(cur *= ak2) %= mod;
	}
	cur = k1;
	X ank2 = bpow <X, X> (a, (n * k2) % phi + phi, mod);	// might overflow here (n * k2)
	for (X p = 1; p <= n; p++) {
		(cur *= ank2) %= mod;
		// X cur = (k1 * bpow <int64_t, int64_t> (a, (k2 * n * p) % phi + phi, mod)) % mod;
		if (vals.count(cur)) {
			return n * p - vals[cur];
		}
	}
	assert (false);
	return -1;
}

template<class X> vector<X> Discrete_Roots (X k, X a, X mod, bool want_all = false) {
	if (a == 0) { return {0}; }
	X g = generator (mod);
	X any_ans = Discrete_Logarithm <X> (g, a, mod, 1, k);
	if (any_ans == -1) return {};
	if (want_all == false) { return {bpow <int64_t, int64_t> (g, any_ans, mod)}; }
	X phi = mod - 1;
	if (Factorisation::is_Prime(mod) == false) phi = Factorisation::Phi (mod); 
	X delta = phi / Factorisation::gcd (phi, k);
	vector<X> ret;
	for (X cur = any_ans % delta; cur < phi; cur += delta) { ret.push_back (bpow <int64_t, int64_t> (g, cur, mod)); }
	// sort (ret.begin(), ret.end());
	return ret;
}

}; // end of namespace Modular_Arithmetics

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, m;
		cin >> a >> b >> m;
		cout << Modular_Arithmetics::Discrete_Logarithm <int64_t> (a, b, m) << '\n';
	}
	return 0;
}
