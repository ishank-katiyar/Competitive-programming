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
 
constexpr int md = (int) 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

template<class X>
class matrix {
 public:
  int row , column;  
  vector<vector<X>> M;
  matrix(vector<vector<X>> MM) {
   row = (int) MM.size();
   column = (int) MM[0].size();
   M = MM;
  }
  matrix(int r , int c) {
   row = r;
   column = c; 
   M.assign(row , vector<X> (column));
  }
  matrix(int r , int c , X value) {
   row = r;
   column = c;
   M.assign(row , vector<X> (column , value));
  }
  vector<X>& operator [] (int idx) {
   if(idx < 0 || idx >= row) {
    throw out_of_range("In matrix : " + to_string(idx) + " is out of range [0 , " + to_string(row - 1) + "]"); 
   }
   return M[idx];
  }
  template<class T> ostream& operator << (matrix<T> a);
  matrix operator + (matrix b);
  matrix operator - (matrix b);
  matrix operator * (matrix b);
  matrix operator / (matrix b);
  matrix operator + (X b);
  matrix operator - (X b); 
  matrix operator * (X b); 
  matrix operator / (X b); 
  matrix operator ^ (int64_t b); 
  void operator += (matrix a);
  void operator -= (matrix a);
  void operator *= (matrix a);
  void operator /= (matrix a);
  void operator += (X b);
  void operator -= (X b); 
  void operator *= (X b); 
  void operator /= (X b); 
  void operator ^= (int64_t b);
  bool operator == (matrix a);
  bool operator != (matrix a);
  matrix transpose();
};

template<class T> ostream& operator << (ostream& cout , matrix<T> a) {
 int row = a.row;
 int column = a.column;
 for(int i = 0; i < row; i++) {
  for(int j = 0; j < column; j++) cout << a[i][j] << ' ';
  cout << " \n"[i != row - 1]; 
 }
 return cout;
}

template<class X> matrix<X> matrix<X>::operator + (matrix<X> b) {
 if(row != b.row || column != b.column) {
  throw logic_error("Addition of matrices with different Dimensions");
 }
 for(int i = 0; i < row; i++) {
  for(int j = 0; j < column; j++) M[i][j] += b[i][j];
 } 
 return *this;
}

template<class X> matrix<X> matrix<X>::operator - (matrix<X> b) {
 if(row != b.row || column != b.column) {
  throw logic_error("Subtraction of matrices with different Dimensions");
 }
 for(int i = 0; i < row; i++) {
  for(int j = 0; j < column; j++) M[i][j] -= b[i][j];
 } 
 return *this;
}

template<class X> matrix<X> matrix<X>::operator * (matrix<X> b) {
 if(column != b.row) {
  throw logic_error("Multiplication of martices with different Dimensions");
 }
 int r = row;
 int col = b.column;
 matrix<X> ret(r , col);
 for(int i = 0; i < r; i++) {
  for(int j = 0; j < col; j++) {
   X value = 0;
   for(int k = 0; k < column; k++) (value += ((M[i][k] % (md - 1)) * (b[k][j] % (md - 1))) % (md - 1)) %= (md - 1);
   ret[i][j] = value;
  }
 }
 return ret;
}

template<class X> matrix<X> matrix<X>::operator / (matrix<X> b) {
 return *this * inv(b);
}

template<class X> matrix<X> matrix<X>::operator + (X b) {
 return *this + matrix(row , column , b);
}

template<class X> matrix<X> matrix<X>::operator - (X b) {
 return *this - matrix(row , column , b);
}

template<class X> matrix<X> matrix<X>::operator * (X b) {
 for(int i = 0; i < row; i++) {
  for(int j = 0; j < column; j++) M[i][j] *= b;
 }
 return *this;
}

template<class X> matrix<X> matrix<X>::operator / (X b) {
 for(int i = 0; i < row; i++) {
  for(int j = 0; j < column; j++) M[i][j] /= b;
 }
 return *this;
}

template<class X> matrix<X> matrix<X>::operator ^ (int64_t b) {
 b--;
 matrix<X> ret = *this;
 matrix<X> a = *this;
 while(b) {
  if(b % 2 == 1) ret = ret * a;
  a = a * a;
  b /= 2;
 }
 return ret;
}

template<class X> void matrix<X>::operator += (matrix<X> b) {*this = *this + b;}
template<class X> void matrix<X>::operator -= (matrix<X> b) {*this = *this - b;}
template<class X> void matrix<X>::operator *= (matrix<X> b) {*this = *this * b;}
template<class X> void matrix<X>::operator /= (matrix<X> b) {*this = *this / b;}
template<class X> void matrix<X>::operator += (X b) {*this = *this + b;}
template<class X> void matrix<X>::operator -= (X b) {*this = *this - b;}
template<class X> void matrix<X>::operator *= (X b) {*this = *this * b;}
template<class X> void matrix<X>::operator /= (X b) {*this = *this / b;}
template<class X> void matrix<X>::operator ^= (int64_t b) {*this = *this ^ b;}
template<class X> bool matrix<X>::operator == (matrix<X> a) {
 for(int i = 0; i < row; i++) {
  for(int j = 0; j < column; j++) if(M[i][j] != a[i][j]) return false;
 }
 return true;
}
template<class X> bool matrix<X>::operator != (matrix<X> a) {return !(*this == a);}

template<class X> matrix<X> matrix<X>::transpose() {
 matrix<X> ret(column , row);
 for(int i = 0; i < column; i++) {
  for(int j = 0; j < row; j++) {
   ret[i][j] = M[j][i];
  }
 }
 return ret;
}
 
/*
Mint fibo_mat(long long int n) {
 matrix<Mint> a(1 , 2 , 1);
 a[0][0] = 0;
 matrix<Mint> P(2 , 2 , 1);
 P[0][0] = 0;
 P ^= n;
 a *= P;
 return a[0][0];
}
*/

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 const int mod_phi = md - 1;
 
 int64_t n, f1, f2, f3, c;
 cin >> n >> f1 >> f2 >> f3 >> c;

 auto get_power_c = [&] (int64_t a1, int64_t a2, int64_t a3, int64_t N) -> int64_t {
  vector<vector<int64_t>> a;
  a.push_back ({0, 1, 0, 0, 0});
  a.push_back ({0, 0, 1, 0, 0});
  a.push_back ({1, 1, 1, 2, -6});
  a.push_back ({0, 0, 0, 1, 1});
  a.push_back ({0, 0, 0, 0, 1});
  matrix <int64_t> T (a);
  T ^= (N - 3);
  vector<vector<int64_t>> b;
  b.push_back ({a1});
  b.push_back ({a2});
  b.push_back ({a3});
  b.push_back ({4});
  b.push_back ({1});
  matrix <int64_t> F (b);
  return (T * F)[2][0] % (md - 1);
 };
 
 auto get = [&] (int64_t a1, int64_t a2, int64_t a3, int64_t N) -> int64_t {
  vector<vector<int64_t>> a;
  a.push_back ({0, 1, 0});
  a.push_back ({0, 0, 1});
  a.push_back ({1, 1, 1});
  matrix <int64_t> T (a);
  T ^= (N - 3);
  vector<vector<int64_t>> b;
  b.push_back ({a1});
  b.push_back ({a2});
  b.push_back ({a3});
  matrix <int64_t> F (b);
  return (T * F)[2][0] % (md - 1);
 };

 debug (get (0, 0, 1, 7));

 Mint ans = power ((Mint) c, get_power_c (0, 0, 0, n) + mod_phi);
 ans *= power ((Mint) f3, get (0, 0, 1, n) + mod_phi);
 ans *= power ((Mint) f2, get (0, 1, 0, n) + mod_phi);
 ans *= power ((Mint) f1, get (1, 0, 0, n) + mod_phi);

 cout << ans << '\n';

 return 0;
}
