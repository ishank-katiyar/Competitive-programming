#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* ch) {
    return to_string((string)ch);
}

string to_string(char ch) {
    return (string)"'" + ch + (string)"'";
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string (__int128 x) {
    string s;
    while (x) s += to_string ((int) (x % 10)), x /= 10;
    reverse (s.begin(), s.end());
    return s;
}

template<class A, class B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class A>
string to_string(A a) {
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

template<class H, class... T>
void debug(H head, T... tail) {
    cerr << to_string(head) << " ";
    debug(tail...);
}

#ifdef LOCAL
    #define debug(...) cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else 
    #define debug(...) 
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() {
    return uniform_int_distribution<int> (1, (int) 1e9) (rng);
}

template<class A> 
A rnd(A x, A y) {
    return uniform_int_distribution<A> (x, y) (rng);
}

using u64 = int64_t;
using u128 = __int128;

u64 binpower(u128 base, u128 e, u128 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u128 n, u128 a, u128 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (__int128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(u128 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u128 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}) {
        if (n == a * u128(1))
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

u128 mult(u128 a, u128 b, u128 mod) {
    // return (__int128)a * b % mod;
    // a %= mod;
    // b %= mod;
    // u128 result = 0;
    // while (b) {
    //     if (b & 1) {
    //         result = (result + a) % mod;
            
    //     }
    //     a = (a + a) % mod;
    //     b >>= 1;
    // }
    // return result;
    a %= mod;
    b %= mod;
    u128 result = 0;
    while (b) {
        if (b & 1) {
            result = result + a;
            if (result >= mod) {
                result -= mod;
            }
        }
        // a = (a + a) % mod;
        a <<= 1;
        if (a >= mod) {
            a -= mod;
        }
        b >>= 1;
    }
    return result;
}

u128 f(u128 x, u128 c, u128 mod) {
    // return (mult(x, x, mod) + c) % mod;
    u128 xx = mult (x, x, mod);
    xx += c;
    if (xx >= mod) {
        xx -= mod;
    }
    return xx;
}

u128 abs128 (u128 ret) {
    if (ret < 0) ret = -ret;
    return ret;
}

template <class X> X gcd(X a, X b) {
    // debug ("gcd", a, b);
    return b == 0 ? a : gcd (b, a % b);
	// if (!a || !b) {
	// 	return a | b;
	// }
	// unsigned shift = __builtin_ctz(a | b);
	// a >>= shift;
	// do {
	// 	b >>= __builtin_ctz(b);
	// 	if (a > b) {
	// 		swap(a, b);
	// 	}
	// 	b -= a;
    //     debug (a, b);
	// } while (b);
	// return a << shift;
}

u128 brent(u128 n, u128 x0=2, u128 c=1) {
    u128 x = x0;
    u128 g = 1;
    u128 q = 1;
    u128 xs, y;
    u128 cnt = 0;

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
                q = mult(q, abs128(y - x), n);
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
            g = gcd(abs128(xs - y), n);
            cnt += 1;
        } while (g == 1);
    }
    // debug (n, g, cnt);
    return g;
}

u128 rho(u128 n, u128 x0=2, u128 c=1) {
    u128 x = x0;
    u128 y = x0;
    u128 g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(abs128(x - y), n);
    }
    return g;
}

u128 pollard_rho(u128 n, u128 c) {
    u128 x = 2, y = 2, i = 1, k = 2, d = -1;
    while (true) {
        // debug (x, y, i, k, d);
        x = (mult(x, x, n) + c);
        if (x >= n)	x -= n;
        d = __gcd(abs128(x - y), n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}

template <class X>
vector<X> trial_division (X N) {
    vector<X> prime;
    for (u64 i = 2; i * i <= N; i++) {
        if (N % i) continue;
        prime.push_back (i);
        while (N % i == 0) N /= i;
    }
    if (N > 1) prime.push_back (N);
    return prime;
}

template<class X>
vector<X> trial_division3 (X n) {
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	u64 n;
	// 	cin >> n;
	// 	cout << (MillerRabin(n) ? "YES" : "NO") << '\n';
	// }
    // int64_t N = rnd <int64_t> (1, 1e14);
    // int64_t nn = N;
    // while (N <= LLONG_MAX) {
    //     if (MillerRabin (N)) {
    //         cout << N << '\n';
    //         cout << N - nn << '\n';
    //         return 0;
    //     }
    //     N += 1;
    // }

    const u128 threshold = 1e13;

    function<vector<u128>(u128)> ff = [&] (u128 N) -> vector<u128> {
        // debug (N);
        if (MillerRabin (N)) {
            return {N};
        }
        if (N <= threshold) {
            return trial_division3 (N);
        }
        u128 pp = brent (N);
        // u128 pp = N;
        // for (u128 i = 2; pp == N; i++) {
        //     debug (i);
        //     pp = pollard_rho (N, i);
        // }
        // debug (N, pp);
        vector<u128> ans = ff (pp);
        for (auto& i: ans) {
            while (N % i == 0) N /= i;
        }
        vector<u128> aa = ff (N);
        for (auto& i: aa) {
            ans.push_back (i);
        }
        return ans;
    };

    string s;
    while (cin >> s) {
        if (s == "0") { break; }
        u128 x = 0;
        for (auto& i: s) {
            x *= 10;
            x += stoi (string (1, i));
        }
        vector<pair<u128, int>> ans;
        for (auto& i: ff (x)) {
            int cnt = 0;
            while (x % i == 0) cnt += 1, x /= i;
            ans.push_back (make_pair (i, cnt));
        }
        sort (ans.begin(), ans.end());
        for (auto& i: ans) cout << to_string(i.first) << '^' << i.second << ' ';
        cout << '\n';
    }
	return 0;
}
