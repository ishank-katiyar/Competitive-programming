#include <bits/stdc++.h>
using namespace std;

static const auto fast_io = [] {
 ios_base::sync_with_stdio(false); 
 cin.tie(nullptr); cout.tie(nullptr); 
 return nullptr;
}();

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() {
 return uniform_int_distribution<int> (1, (int) 1e9) (rng);
}

template<class A> 
A rnd(A x, A y) {
 return uniform_int_distribution<A> (x, y) (rng);
}

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

string to_string(vector<bool> v) {
 bool first = true;
 string res = "{";
 for (int i = 0; i < static_cast<int>(v.size()); i++) {
  if (!first) {
   res += ", ";
  }
  first = false;
  res += to_string(v[i]);
 }
 res += "}";
 return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
 string res = "";
 for (size_t i = 0; i < N; i++) {
  res += static_cast<char>('0' + v[i]);
 }
 return res;
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

template<class A, class B, class C>
string to_string(priority_queue<A, B, C> a) {
 vector<A> res;
 while(a.empty() == false) {
  res.push_back(a.top());
  a.pop();
 }
 reverse(res.begin(), res.end());
 return to_string(res);
}

template<class A>
string to_string(priority_queue<A> a) {
 vector<A> res;
 while(a.empty() == false) {
  res.push_back(a.top());
  a.pop();
 }
 reverse(res.begin(), res.end());
 return to_string(res);
}

template<class A>
string to_string(stack<A> a) {
 vector<A> res;
 while(a.empty() == false) {
  res.push_back(a.top());
  a.pop();
 }
 return to_string(res);
}

template<class A>
string to_string(queue<A> a) {
 vector<A> res;
 while(a.empty() == false) {
  res.push_back(a.front());
  a.pop();
 }
 return to_string(res);
}

vector<string> __vector_tuple;
template<int index, class... A>
struct print_tuple {
 auto operator() (tuple<A...> a) {
  __vector_tuple.push_back(to_string(get<index>(a)));
  print_tuple<index-1, A...>{}(a);
 }
};

template<class... A>
struct print_tuple<0, A...> {
 auto operator() (tuple<A...> a) {
  __vector_tuple.push_back(to_string(get<0>(a)));
 }
};

template<class... T>
string to_string(tuple<T...> a) {
 const int ttsz = tuple_size<decltype(a)>::value;
 print_tuple<ttsz-1, T...>{}(a);
 string __ss = to_string(__vector_tuple);
 __vector_tuple.clear();
 return __ss;
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

typedef long long int ll;

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
   uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
   uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
   asm(
     "divl %4; \n\t"
     : "=a" (d), "=d" (m)
     : "d" (xh), "a" (xl), "r" (mod())
   );
   value = m;
#else
   value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
   return *this;
 }
 template <typename U = T>
 typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
  int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
  value = normalize(value * rhs.value - q * mod());
  return *this;
 }
 template <typename U = T>
 typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
  value = normalize(value * rhs.value);
  return *this;
 }
 
 Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
 template <typename U>
 friend const Modular<U>& abs(const Modular<U>& v) { return v; }
 
 template <typename U>
 friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
 template <typename U>
 friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
 template <typename U>
 friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
 assert(b >= 0);
 Modular<T> x = a, res = 1;
 U p = b;
 while (p > 0) {
   if (p & 1) res *= x;
   x *= x;
   p >>= 1;
 }
 return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
 return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
 return to_string(number());
}
 
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
 return stream << number();
}
 
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
 typename common_type<typename Modular<T>::Type, int64_t>::type x;
 stream >> x;
 number.value = Modular<T>::normalize(x);
 return stream;
}
 
/*
using ModType = int;
 
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/
 
constexpr int md = (int) 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

const int maxn = 510000;
vector<Mint> fact(maxn, (Mint) 1);

Mint nck(int n, int r) {
 if(r > n) return 0;
 Mint deno = fact[r] * fact[n-r];
 Mint ans = fact[n] / deno;
 return ans;
}

int main()
{
 fact[0] = fact[1] = 1;
 for(int i = 2; i < maxn; i++) fact[i] *= (fact[i-1] * (Mint) i);
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> c(n+1, 0);
  for(auto& i: a) cin >> i, c[i]++;
  vector<pair<int, int>> cc;
  for(int i = 1; i <= n; i++) if(c[i] > 0) cc.push_back(make_pair(i, c[i]));
  int sz = (int) cc.size();
  vector<vector<Mint>> ar(sz);
  vector<Mint> precompute(n+1, (Mint) 1);
  for(int i = 0; i < sz; i++) ar[i].assign(cc[i].second + 1, (Mint) 1);
  for(int i = 0; i < sz; i++) {
   int cnt = cc[i].second;
   Mint sum = 1;
   for(int j = 1; j <= cnt; j++) {
    if(i > 0) ar[i][j] *= precompute[j-1];
   }
   for(int j = 1; j <= cnt; j++) {
    sum += nck(cnt, j);
    precompute[j] *= sum;
   }
  }
  debug("prefix", ar);
  precompute.assign(n+1, (Mint) 1);
  vector<int> cnt_p2(n+1, 0);
  for(int i = sz-1; i >= 0; i--) {
   int cnt = cc[i].second;
   Mint sum = 1;
   for(int j = 1; j <= cnt; j++) {
    if(i != sz-1) ar[i][j] *= precompute[j];
    if(i != sz-1 && cnt_p2[j-1] > 0 && j > 1) ar[i][j] *= power((Mint) 2, cnt_p2[j-1] * (j-1));
   }
   for(int j = 1; j <= cnt; j++) {
    sum += nck(cnt, j);
    precompute[j] *= sum;
   }
   cnt_p2[cnt]++;
  }
  debug("suffix with 2**(j-1)", ar);
  for(int i = 1; i <= n; i++) cnt_p2[i] *= i;
  for(int i = 1; i <= n; i++) cnt_p2[i] += cnt_p2[i-1];
  for(int i = 0; i < sz; i++) {
   int cnt = cc[i].second;
   for(int j = 2; j <= cnt; j++) {
    ar[i][j] *= power((Mint) 2, cnt_p2[j-2]);
   }
  }
  debug("Total mul", ar);
  for(int i = 0; i < sz; i++) {
   int cnt = cc[i].second;
   for(int j = 1; j <= cnt; j++) {
    ar[i][j]--;
    ar[i][j] *= nck(cnt, j);
   }
  }
  debug("without same no", ar);
  vector<Mint> ans(n+1);
  for(int i = 0; i < sz; i++) {
   int x = cc[i].first;
   int cnt = cc[i].second;
   for(int j = 1; j <= cnt; j++) ans[x] += ar[i][j];
   ans[x] += power((Mint) 2, cnt) - (Mint) 1;
  }
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << '\n';
 }
 return 0;
}
