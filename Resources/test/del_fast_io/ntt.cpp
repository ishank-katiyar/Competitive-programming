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

template<typename T>
class NTT {
public:
	using U = typename decay<decltype(T::value)>::type;

	static U md;
	static mod<T> root;
	static int base;
	static int max_base;
	static vector<int> rev;
	static vector<mod<T>> roots;

	static void clear() { root = md = base = max_base = 0; rev.clear(), roots.clear(); }

	static void init () {
		md = T::value;
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
		if (md != T::value) { clear(); }
		if (roots.empty() || rev.empty()) { init(); }
		if (base >= new_base) { return; }
		assert (new_base <= max_base);
		rev.resize(1 << new_base);
		for (int i = 0; i < (1 << new_base); i++) { rev[i] = (rev[i / 2] >> 1) | (i % 2) << (new_base - 1); }
		roots.resize(1 << new_base);
		while (base < new_base) {
			const mod<T> z = bpow (root, 1 << (max_base - base - 1));
			for (int i = 1 << (base - 1); i < (1 << base); i++) {
				roots[i << 1] = roots[i];
				roots[(i << 1) + 1] = roots[i] * z;
			}
			base++;
		}
	}

	static void ntt (vector<mod<T>> &a) {
		int n = a.size();
		int zeros = __builtin_ctz (n);
		ensure_base (zeros);
		int shift = base - zeros;
		for (int i  = 0; i < n; i++) { if (i < (rev[i] >> shift)) swap (a[i], a[rev[i] >> shift]); }
		for (int k = 1; k < n; k *= 2) {
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					mod<T> x = a[i + j], y = a[i + j + k] * roots[j + k];
					a[i + j] = x + y;
					a[i + j + k] = x - y;
				}
			}
		}
	}

	static vector<mod<T>> multiply (vector<mod<T>> a, vector<mod<T>> b) {
		if (a.empty() || b.empty()) return {};
		int total = int (a.size() + b.size()) - 1;
		int n = 1 << (32 - __builtin_clz(total));
		vector<mod<T>> A (a), B (b);
		A.resize (n), B.resize (n);
		ntt (A);
		if (b != a) ntt (B); else B = A;
		mod<T> inv_n = 1 / static_cast <mod<T>> (n);
		for (int i = 0; i < n; i++) { A[i] *= B[i] * inv_n; }
		ntt (A);
		reverse (A.begin() + 1, A.end());
		A.resize (total);
		return A;
	}
};

template <typename T> typename NTT <T>::U NTT <T>::md;
template <typename T> mod<T> NTT <T>::root;
template <typename T> int NTT <T>::base;
template <typename T> int NTT <T>::max_base;
template <typename T> vector<int> NTT <T>::rev;
template <typename T> vector<mod<T>> NTT <T>::roots;

template<typename T>
vector<mod<T>> operator * (const vector<mod<T>>& A, const vector<mod<T>>& B) { 
	if (A.empty() || B.empty()) { return {}; }
	if (min ((int) A.size(),(int) B.size()) <= 250) {
		vector<mod<T>> C ((int) A.size() + (int) B.size() - 1, 0);
		for (int i = 0; i < (int) A.size(); i++) {
			for (int j = 0; j < (int) B.size(); j++) {
				C[i + j] += A[i] * B[j];
			}
	}
		return C;
	}
	return NTT <T> :: multiply (A, B); 
}
template<typename T>
vector<mod<T>> operator *= (vector<mod<T>>& A, const vector<mod<T>>& B) { return A = A * B; }

static const int buf_len = (1 << 14);
static const int buf_max = (1 << 04);
static char buf_out[buf_len];
static char buf_num[buf_max];
static int buf_pos = 0;

inline void writeChar(int x) {
    if (buf_pos == buf_len) fwrite(buf_out, 1, buf_len, stdout), buf_pos = 0;
    buf_out[buf_pos++] = x;
}

inline void writeInt(int x, char end = 0) {
    if (x < 0) writeChar('-'), x = -x;
    int n = 0;
    do buf_num[n++] = x % 10 + '0'; while(x /= 10);
    while (n--) writeChar(buf_num[n]);
    if (end) writeChar(end);
}

struct Flusher{~Flusher(){if(buf_pos)fwrite(buf_out, 1, buf_pos, stdout),buf_pos=0;}}flusher;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// std::cin.tie(0)->sync_with_stdio(0);
	// FastIO::Reader cin;
	// FastIO::Writer cout;
	// using Mod1 = mod <7340033>;
	// Mod1 x = 5;
	// x /= 10;
	// cout << x << '\n';
	// cout << bpow <Mod1, int> (5, 1 << 20) << '\n';
	// cout << bitset <40> (7340032) << '\n';
	// cout << bitset<40> (998244352) << '\n';
	// cout << __builtin_ctz (998244352) << '\n';
	// cout << Mod::MOD << '\n';
	string a, b;
	cin >> a >> b;
	vector<Mod> aa (a.begin(), a.end()), bb (b.begin(), b.end());
	for_each (aa.begin(), aa.end(), [](Mod &x) -> Mod {x -= int('0'); return x;});
	for_each (bb.begin(), bb.end(), [](Mod &x) -> Mod {x -= int('0'); return x;});
	// reverse (aa.begin(), aa.end());
	// reverse (bb.begin(), bb.end());
	debug (aa, bb);
	aa *= bb;
	debug (aa);
	// reverse(aa.begin(), aa.end());
	// Mod carry = 0;
	// for (int i = (int) aa.size()- 1; i >= 0; i--) {
	// 	aa[i] += carry;
	// 	carry = aa[i] / 10;
	// 	aa[i] %= 10;
	// }
	// aa.front() += carry * 10;
	// debug (aa);
	// for(auto& i: aa) cout << i;
	// cout << '\n';
	cout << to_string (aa) << '\n';
	// for (auto& i: to_string (aa)) writeChar(i);
	// writeChar('\n');
	// Flusher();
	return 0;
}
