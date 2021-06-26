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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
 int n = a.size();

 for (int i = 1, j = 0; i < n; i++) {
  int bit = n >> 1;
  for (; j & bit; bit >>= 1)
	  j ^= bit;
  j ^= bit;

  if (i < j) swap(a[i], a[j]);
 }

 for (int len = 2; len <= n; len <<= 1) {
  double ang = 2 * PI / len * (invert ? -1 : 1);
  cd wlen(cos(ang), sin(ang));
  for (int i = 0; i < n; i += len) {
   cd w(1);
   for (int j = 0; j < len / 2; j++) {
	cd u = a[i+j], v = a[i+j+len/2] * w;
	a[i+j] = u + v;
	a[i+j+len/2] = u - v;
	w *= wlen;
   }
  }
 }

 if (invert) {
  for (cd & x : a) x /= n;
 }
}

vector<int64_t> multiply(vector<int64_t> const& a, vector<int64_t> const& b) {
 vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());

 int n = 1;
 int sz_sum = (int) a.size() + (int) b.size();
 while (n < sz_sum) n <<= 1;
 fa.resize(n);
 fb.resize(n);

 fft(fa, false);
 fft(fb, false);
 for (int i = 0; i < n; i++) fa[i] *= fb[i];
 fft(fa, true);

 vector<int64_t> result(n);
 for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
 return result;
}

vector<int64_t> normalize(vector<int64_t> A) {
 int carry = 0;
 for (auto& i: A) {
  i += carry;
  carry = i / 10;
  i = i % 10;
 }
 reverse (A.begin(), A.end());
 return A;
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<int64_t> a(n); 
 for (auto& i: a) cin >> i;
 vector<int64_t> b(n); 
 for (auto& i: b) cin >> i;
 reverse (a.begin(), a.end());
 reverse (b.begin(), b.end());
 vector<int64_t> mul = multiply(a, b);
 debug (mul);
 mul = normalize(mul);
 for (auto& i: mul) cout << i << ' ';
 cout << '\n';
 return 0;
}
