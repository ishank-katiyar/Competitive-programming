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
 
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

class DSU {
public:
 int n;
 vector<int> Parent;
 vector<int> Size;
 DSU (int N) {
  n = N;
  Parent.assign(n + 1, 0);
  Size.assign(n + 1, 0);
  make_set();
 }
 
 void make_set() {
  for(int i = 0; i <= n; i++) {
   Parent[i] = i;
   Size[i] = 1;
  }
 }
 
 int rep(int N) {
  if(Parent[N] == N) return N;
  return Parent[N] = rep(Parent[N]);
 }
 
 void Union(int A, int B) {
  int RA = rep(A);
  int RB = rep(B);
  if(RA != RB) {
   if(Size[RA] < Size[RB]) {
    swap(RA, RB);
   }
   Parent[RB] = RA;
   Size[RA] += Size[RB];
  }
 }
};



int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int c, n, m;
  cin >> c >> n >> m;

  vector<vector<pair<int, int>>> club (c);

  vector<pair<pair<int, int>, int>> a;

  for (int i = 0; i < c; i++) {
   int x;
   cin >> x;
   for (int j = 0; j < x; j++) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    club[i].push_back (p);
    a.push_back (make_pair (p, i));
   }
  }

  // auto f = [&] (vector<pair<int, int>> a, vector<pair<int, int>> b) -> bool {
  //  // auto intersect = [] (pair<int,int> x, pair<int, int> y) -> bool {
  //  //  return (x.first >= y.first && x.first <= y.second) || (x.second >= y.first && x.second <= y.second);
  //  // };
  //  // for (auto& i: a) {
  //  //  for (auto& j: b) {
  //  //   ok |= intersect (i, j);
  //  //  }
  //  // }
  //  bool ok = false;
  //  map<int, int> mp;
  //  for (auto& i: a) {
  //   mp[i.first] += 1;
  //   mp[i.second + 1] -= 1;
  //  }
  //  for (auto& i: b) {
  //   mp[i.first] += 1;
  //   mp[i.second + 1] -= 1;
  //  }
  //  vector<pair<int, int>> ss;
  //  for (auto& i: mp) {
  //   ss.push_back (i);
  //  }
  //  int sum = 0;
  //  for (auto& i: ss) {
  //   sum += i.second;
  //   if (sum > 1) {
  //    ok = true;
  //   }
  //  }
  //  assert (sum == 0);
  //  return ok;
  // };

  DSU d (c);

  // for (int i = 0; i < c; i++) {
  //  for (int j = i + 1; j < c; j++) {
  //   if (f (club[i], club[j]) == true) {
  //    d.Union (i, j);
  //   }
  //  }
  // }

  sort (a.begin(), a.end());


  int sz = static_cast <int> (a.size());

  int I = 0;

  while (I < sz) {
   int rr = a[I].first.second;
   int j = I;
   while (j < sz && a[j].first.first <= rr) {
    rr = max (rr, a[j].first.second);
    j += 1;
   }
   j -= 1;
   for (int k = I + 1; k <= j; k++) {
    d.Union (a[k].second, a[k - 1].second);
   }
   I = j + 1;
  }

  int cnt = 0;

  for (int i = 0; i < c; i++) {
   cnt += (d.Parent[i] == i);
  }
  debug (cnt);

  // count zero club students

  int cnt1 = 0;
  map <int, int> mp;
  for (int i = 0; i < c; i++) {
   for (auto& j: club[i]) {
    mp[j.first] += 1;
    mp[j.second + 1] -= 1;
   }
  }
  vector<pair<int, int>> ss;
  for (auto& i: mp) {
   if (i.second == 0) {
    continue;
   }
   ss.push_back (i);
  }
  int sum = 0;
  cnt1 += ss[0].first - 1;
  sz = static_cast <int> (ss.size());
  debug (ss);
  for (int i = 0; i < sz; i++) {
   sum += ss[i].second;
   if (sum == 0) {
    int l = ss[i].first;
    if (i < sz - 1) {
     int r = ss[i + 1].first; 
     debug (r, l);
     cnt1 += r - l;
    } else {
     debug (n, l);
     cnt1 += n - l + 1;
    }
   }
  }
  cnt += cnt1;
  debug (cnt);
  cout << power ((Mint) m, cnt) << '\n';
 }
 return 0;
}
