#include <bits/stdc++.h>

using namespace std;

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
	// friend mod inverse (const mod& x) { return mod(bpow <T, T> (x.value, MOD - 2, MOD)); }
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

const int md = 1e9 + 7;
using Mod = mod <md>;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 int x;
 cin >> x;
 int p;
 cin >> p;
 const int maxn = 1110;
 vector<Mod> fact (maxn, (Mod) 1);
 for (int i = 2; i < maxn; i++) fact[i] *= fact[i - 1] * i;
 assert (x <= n);
 // {{{
 // vector<int> a;
 // for (int i = 1; i <= n; i++) a.push_back (i);
 // 
 // auto f = [&] (int X) -> bool {
 //  int left = 0;
 //  int right = n;
 //  while (left < right) {
 //   int mid = (left + right) / 2;
 //   if (a[mid] <= X) left = mid + 1;
 //   else right = mid;
 //  }
 //  if (left > 0 && a[left - 1] == X) return true;
 //  return false;
 // };
 // 
 // vector<int> pos (n, 0);
 // int cnt = 0;
 // if (f(x) && x == p) {
 //  cout << ++cnt << ":  ";
 //  for (auto& i: a) cout << i << ' ';
 //  pos[x - 1]++;
 //  cout << '\n';
 // }
 // while (next_permutation (a.begin(), a.end())) {
 //  int pp = (find (a.begin(), a.end(), x) - a.begin());
 //  pp++;
 //  if (pp != p) continue;
 //  if (f (x)) {
 //   cout << ++cnt << ":  ";
 //   for (auto& i: a) cout << i << ' ';
 //   pos[(find (a.begin(), a.end(), x) - a.begin())]++;
 //   cout << '\n';
 //  }
 // }
 // cout << '\n';
 // for (auto& i: pos) cout << i << ' ';
 // cout << '\n';
 // }}}
 Mod ans = 1;
 int cnt = 0;
 int l = 0, r = n;
 int f = x - 1;
 int s = n - x;
 while (l < r) {
  cnt++;
  int m = (l + r) / 2;
  if (m < p) {
   ans *= (f--), l = m + 1;
  }
  else if (m == p) {
   l = m + 1;
  }
  else {
   ans *= (s--), r = m;
  }
 }
 cout << fact[n - cnt] * ans << '\n';
 return 0;
}
