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
	constexpr static T MOD = X::value;
	static_assert (MOD <= 3037000499);

  template<typename U>
	T normalize(const U& x) {
    T y;
		if (x < -MOD || x >= MOD) y = static_cast<T> (x % MOD);
    else y =  static_cast<T> (x);
		if (y < 0) y += MOD;
		return y;
	}

	mod () : value(0) {}
	template<typename U> mod (const U& x) : value(normalize(x)) {}

	const T& operator ()() const { return value; }
	template<typename U> mod<U> inverse (const mod<U>& x) { 
    return mod<U> (bpow <typename decay<decltype(U::value)>::type, typename decay<decltype(U::value)>::type> (x.value, U::value - 2, U::value)); 
  }

	template <typename U> friend ostream& operator << (ostream& out, const mod<U>& x) { out << x.value; return out; }
	template <typename U> friend istream& operator >> (istream& in, mod<U>& x) { typename decay<decltype(U::value)>::type tmp; in >> tmp; x = mod<U> (tmp); return in; }
	mod& operator += (const mod& x) { if ((value += x.value) >= MOD) value -= MOD; return *this; }
	mod& operator -= (const mod& x) { if ((value -= x.value) < 0) value += MOD; return *this; }
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

template <typename T>
class NTT {
 public:
  using U = typename decay<decltype(T::value)>::type;

  static U md;
  static mod<T> root;
  static int base;
  static int max_base;
  static vector<mod<T>> roots;
  static vector<int> rev;

  static void clear() {
    root = 0;
    base = 0;
    max_base = 0;
    roots.clear();
    rev.clear();
  }

  static void init() {
    md = T::value;
    assert(md >= 3 && md % 2 == 1);
    auto tmp = md - 1;
    max_base = 0;
    while (tmp % 2 == 0) {
      tmp /= 2;
      max_base++;
    }
    root = 2;
    while (bpow (root, (md - 1) >> 1) == 1) {
      root++;
    }
    assert(bpow (root, md - 1) == 1);
    root = bpow (root, (md - 1) >> max_base);
    base = 1;
    rev = {0, 1};
    roots = {0, 1};
  }

  static void ensure_base(int nbase) {
    if (md != T::value) {
      clear();
    }
    if (roots.empty()) {
      init();
    }
    if (nbase <= base) {
      return;
    }
    assert(nbase <= max_base);
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      mod<T> z = bpow (root, 1 << (max_base - 1 - base));
      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = roots[i] * z;
      }
      base++;
    }
  }

  static void fft(vector<mod<T>> &a) {
    int n = (int) a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          mod<T> x = a[i + j];
          mod<T> y = a[i + j + k] * roots[j + k];
          a[i + j] = x + y;
          a[i + j + k] = x - y;
        }
      }
    }
  }

  static vector<mod<T>> multiply(vector<mod<T>> a, vector<mod<T>> b) {
    if (a.empty() || b.empty()) {
      return {};
    }
    int eq = (a == b);
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    if (eq) b = a; else fft(b);
    mod<T> inv_sz = 1 / static_cast<mod<T>>(sz);
    for (int i = 0; i < sz; i++) {
      a[i] *= b[i] * inv_sz;
    }
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(need);
    return a;
  }
};

template <typename T> typename NTT<T>::U NTT<T>::md;
template <typename T> mod<T> NTT<T>::root;
template <typename T> int NTT<T>::base;
template <typename T> int NTT<T>::max_base;
template <typename T> vector<mod<T>> NTT<T>::roots;
template <typename T> vector<int> NTT<T>::rev;

template <typename T>
vector<mod<T>> operator*(const vector<mod<T>>& a, const vector<mod<T>>& b) {
  if (a.empty() || b.empty()) {
    return {};
  }
  if (min(a.size(), b.size()) < 150) {
    vector<mod<T>> c(a.size() + b.size() - 1, 0);
    for (int i = 0; i < (int) a.size(); i++) {
      for (int j = 0; j < (int) b.size(); j++) {
        c[i + j] += a[i] * b[j];
      }
    }
    return c;
  }
  return NTT<T>::multiply(a, b);
}

template <typename T>
vector<mod<T>>& operator*=(vector<mod<T>>& a, const vector<mod<T>>& b) {
  return a = a * b;
}

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
  ios::sync_with_stdio(false);
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
					gr[cnt].add (i, j);
				}
			}
		}
	}
	for (int i = 0; i < n - m + 1; i++) {
		int ans = 0;
		for (int j = 0; j < 6; j++) {
			if (gr[i].covered[j] == false) {
				gr[i].dfs (j);
				ans += 1;
			}
		}
		cout << 6 - ans << ' ';
	}
	cout << '\n';
  // Mod x = 5, y = 10;
  // cout << 1 / x << '\n';
  // cout << x << '\n';
  // x += 10;
  // x /= 5;
  // cout << x << '\n';
  // x *= y;
  // x += y;
  // x /= y;
  // x++, --x;
  // cout << x << '\n';
  // cout << bpow (x, 10) << '\n';
  return 0;
}
