#ifdef LOCAL
 #include <P.hpp>
 #include <debugger.hpp>
 #define __int64 __int64_t
#else 
 #include <bits/stdc++.h>
 #define debug(a...) //
 // #define __int64 long long int
#endif
using namespace std;

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

const int base = 1000000000;
const int base_digits = 9; 
struct bigint {
	vector<__int64> a;
	int sign = 1;

	bigint() :
		sign(1) {
	}
 
	bigint(long long v) {
		*this = v;
	}
 
	bigint(const string &s) {
		read(s);
	}

 bigint(const bigint &v) {
  this->a = v.a;
 }

	int size(){
		if(a.empty())return 0;
		int ans=(a.size()-1)*base_digits;
		int ca=a.back();
		while(ca)
			ans++,ca/=10;
		return ans;
	}
	bigint operator ^(const bigint &v){
		bigint ans = 1 , aa = *this , b = v;
		while(!b.isZero()){
			if(b % 2)
				ans *= aa;
			aa *= aa;
   b /= 2;
		}
		return ans;
	}
	string to_string(){
		stringstream ss;
		ss << *this;
		string s;
		ss >> s;
		return s;
	}
	int sumof(){
		string s = to_string();
		int ans = 0;
		for(auto c : s)  ans += c - '0';
		return ans;
	}

	void operator=(const bigint &v) {
		sign = v.sign;
		a = v.a;
	}
 
	void operator=(long long v) {
		sign = 1;
		a.clear();
		if (v < 0)
			sign = -1, v = -v;
		for (; v > 0; v = v / base)
			a.push_back(v % base);
	}
 
	bigint operator+(const bigint &v) const {
		if (sign == v.sign) {
			bigint res = v;
 
			for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
				if (i == (int) res.a.size())
					res.a.push_back(0);
				res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
				carry = res.a[i] >= base;
				if (carry)
					res.a[i] -= base;
			}
			return res;
		}
		return *this - (-v);
	}
 
	bigint operator-(const bigint &v) const {
		if (sign == v.sign) {
			if (abs() >= v.abs()) {
				bigint res = *this;
				for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
					res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
					carry = res.a[i] < 0;
					if (carry)
						res.a[i] += base;
				}
				res.trim();
				return res;
			}
			return -(v - *this);
		}
		return *this + (-v);
	}
 
	void operator*=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
			if (i == (int) a.size())
				a.push_back(0);
			long long cur = a[i] * (long long) v + carry;
			carry = (int) (cur / base);
			a[i] = (int) (cur % base);
			//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
		}
		trim();
	}
 
	bigint operator*(int v) const {
		bigint res = *this;
		res *= v;
		return res;
	}
 
	void operator*=(long long v) {
		if (v < 0)
			sign = -sign, v = -v;
		if(v > base){
			*this = *this * (v / base) * base + *this * (v % base);
			return ;
		}
		for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
			if (i == (int) a.size())
				a.push_back(0);
			long long cur = a[i] * (long long) v + carry;
			carry = (int) (cur / base);
			a[i] = (int) (cur % base);
			//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
		}
		trim();
	}
 
	bigint operator*(long long v) const {
		bigint res = *this;
		res *= v;
		return res;
	}
 
	friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
		int norm = base / (b1.a.back() + 1);
		bigint a = a1.abs() * norm;
		bigint b = b1.abs() * norm;
		bigint q, r;
		q.a.resize(a.a.size());
 
		for (int i = a.a.size() - 1; i >= 0; i--) {
			r *= base;
			r += a.a[i];
			int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
			int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
			int d = ((long long) base * s1 + s2) / b.a.back();
			r -= b * d;
			while (r < 0)
				r += b, --d;
			q.a[i] = d;
		}
 
		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return make_pair(q, r / norm);
	}
 
	bigint operator/(const bigint &v) const {
		return divmod(*this, v).first;
	}
 
	bigint operator%(const bigint &v) const {
		return divmod(*this, v).second;
	}
 
	void operator/=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
			long long cur = a[i] + rem * (long long) base;
			a[i] = (int) (cur / v);
			rem = (int) (cur % v);
		}
		trim();
	}
 
	bigint operator/(int v) const {
		bigint res = *this;
		res /= v;
		return res;
	}
 
	__int64 operator%(__int64 v) const {
  bigint modd = v;
		bigint m = 0;
		for (int i = a.size() - 1; i >= 0; --i) {
			bigint x = m * bigint(base);
   bigint xx = a[i];
			m = (xx + x) % modd;
		}
		return m.longValue();
	}
 
	void operator+=(const bigint &v) {
		*this = *this + v;
	}
	void operator-=(const bigint &v) {
		*this = *this - v;
	}
	void operator*=(const bigint &v) {
		*this = *this * v;
	}
	void operator/=(const bigint &v) {
		*this = *this / v;
	}
 
	bool operator<(const bigint &v) const {
		if (sign != v.sign)
			return sign < v.sign;
		if (a.size() != v.a.size())
			return a.size() * sign < v.a.size() * v.sign;
		for (int i = a.size() - 1; i >= 0; i--)
			if (a[i] != v.a[i])
				return a[i] * sign < v.a[i] * sign;
		return false;
	}
 
	bool operator>(const bigint &v) const {
		return v < *this;
	}
	bool operator<=(const bigint &v) const {
		return !(v < *this);
	}
	bool operator>=(const bigint &v) const {
		return !(*this < v);
	}
	bool operator==(const bigint &v) const {
		return !(*this < v) && !(v < *this);
	}
	bool operator!=(const bigint &v) const {
		return *this < v || v < *this;
	}
 
	void trim() {
		while (!a.empty() && !a.back())
			a.pop_back();
		if (a.empty())
			sign = 1;
	}
 
	bool isZero() const {
		return a.empty() || (a.size() == 1 && !a[0]);
	}
 
	bigint operator-() const {
		bigint res = *this;
		res.sign = -sign;
		return res;
	}
 
	bigint abs() const {
		bigint res = *this;
		res.sign *= res.sign;
		return res;
	}
 
	long long longValue() const {
		long long res = 0;
		for (int i = a.size() - 1; i >= 0; i--)
			res = res * base + a[i];
		return res * sign;
	}
 
	friend bigint gcd(const bigint &a, const bigint &b) {
		return b.isZero() ? a : gcd(b, a % b);
	}
	friend bigint lcm(const bigint &a, const bigint &b) {
		return a / gcd(a, b) * b;
	}
 
	void read(const string &s) {
		sign = 1;
		a.clear();
		int pos = 0;
		while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int i = s.size() - 1; i >= pos; i -= base_digits) {
			int x = 0;
			for (int j = max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			a.push_back(x);
		}
		trim();
	}
 
	friend istream& operator>>(istream &stream, bigint &v) {
		string s;
		stream >> s;
		v.read(s);
		return stream;
	}
 
	friend ostream& operator<<(ostream &stream, const bigint &v) {
		if (v.sign == -1)
			stream << '-';
		stream << (v.a.empty() ? 0 : v.a.back());
		for (int i = (int) v.a.size() - 2; i >= 0; --i)
			stream << setw(base_digits) << setfill('0') << v.a[i];
		return stream;
	}
 
	static vector<__int64> convert_base(const vector<__int64> &a, int old_digits, int new_digits) {
		vector<long long> p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < (int) p.size(); i++)
			p[i] = p[i - 1] * 10;
		vector<__int64> res;
		long long cur = 0;
		int cur_digits = 0;
		for (int i = 0; i < (int) a.size(); i++) {
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back(int(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int) cur);
		while (!res.empty() && !res.back())
			res.pop_back();
		return res;
	}
 
	typedef vector<long long> vll;
 
	static vll karatsubaMultiply(const vll &a, const vll &b) {
		int n = a.size();
		vll res(n + n);
		if (n <= 32) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}
 
		int k = n >> 1;
		vll a1(a.begin(), a.begin() + k);
		vll a2(a.begin() + k, a.end());
		vll b1(b.begin(), b.begin() + k);
		vll b2(b.begin() + k, b.end());
 
		vll a1b1 = karatsubaMultiply(a1, b1);
		vll a2b2 = karatsubaMultiply(a2, b2);
 
		for (int i = 0; i < k; i++)
			a2[i] += a1[i];
		for (int i = 0; i < k; i++)
			b2[i] += b1[i];
 
		vll r = karatsubaMultiply(a2, b2);
		for (int i = 0; i < (int) a1b1.size(); i++)
			r[i] -= a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++)
			r[i] -= a2b2[i];
		for (int i = 0; i < (int) r.size(); i++)
			res[i + k] += r[i];
		for (int i = 0; i < (int) a1b1.size(); i++)
			res[i] += a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++)
			res[i + n] += a2b2[i];
		return res;
	}
 
	bigint operator*(const bigint &v) const {
		vector<__int64> a6 = convert_base(this->a, base_digits, 6);
		vector<__int64> b6 = convert_base(v.a, base_digits, 6);
		vll aa(a6.begin(), a6.end());
		vll b(b6.begin(), b6.end());
		while (aa.size() < b.size())
			aa.push_back(0);
		while (b.size() < aa.size())
			b.push_back(0);
		while (aa.size() & (aa.size() - 1))
			aa.push_back(0), b.push_back(0);
		vll c = karatsubaMultiply(aa, b);
		bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int) c.size(); i++) {
			long long cur = c[i] + carry;
			res.a.push_back((int) (cur % 1000000));
			carry = (int) (cur / 1000000);
		}
		res.a = convert_base(res.a, 6, base_digits);
		res.trim();
		return res;
	}
};


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
  matrix operator ^ (__int64 b); 
  void operator += (matrix a);
  void operator -= (matrix a);
  void operator *= (matrix a);
  void operator /= (matrix a);
  void operator += (X b);
  void operator -= (X b); 
  void operator *= (X b); 
  void operator /= (X b); 
  void operator ^= (__int64 b);
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
   for(int k = 0; k < column; k++) value += (M[i][k] * b[k][j]);
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

template<class X> matrix<X> matrix<X>::operator ^ (__int64 b) {
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
template<class X> void matrix<X>::operator ^= (__int64 b) {*this = *this ^ b;}
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

Mint fibo_mat(__int64 n) {
 matrix<Mint> a(1 , 2 , 1);
 a[0][0] = 0;
 matrix<Mint> P(2 , 2 , 1);
 P[0][0] = 0;
 P ^= n;
 a *= P;
 return a[0][0];
}

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 bigint n;
 cin >> n;
 __int64 pw = n % 1000000014000000048LL;
 cout << fibo_mat(pw) << '\n';
 return 0;
}
