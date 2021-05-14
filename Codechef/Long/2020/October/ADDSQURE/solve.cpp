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

vector<long long> multiply(vector<long long> const& a, vector<long long> const& b) {
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

 vector<long long int> result(n);
 for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
 return result;
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int W, H, n, m;
 cin >> W >> H >> n >> m;
 const int maxa = max(W, H);
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 vector<int> b(m);
 vector<int> c_b(maxa + 1);
 for (auto& i: b) cin >> i, c_b[i]++;

 sort (a.begin(), a.end());
 sort (b.begin(), b.end());

 auto get = [&] (vector<int> A) -> vector<int> {
  int sz = 2 * maxa;
  vector<long long> aa (sz + 1);
  vector<long long> bb (sz + 1);
  for (auto& i: A) {
   assert (maxa + i < sz + 1);
   aa[maxa + i]++;
   assert (maxa - i >= 0);
   bb[maxa - i]++;
  }
  vector<long long> mul = multiply(aa, bb);
  vector<int> diff(maxa + 1);
  int SZ = (int) mul.size();
  assert (SZ >= 2 * maxa);
  for (int i = 2 * maxa; i <= min(SZ - 1, 3 * maxa); i++) {
   diff[i - 2 * maxa] = mul[i];
  }
  return diff;
 };

 vector<int> diff_a = get(a);
 vector<int> diff_b = get(b);

 set<int> s;
 const int MN = min(W, H);
 for (int i = 1; i <= MN; i++) if (diff_a[i] > 0) s.insert (i);
 int ans = 0;
 for (int i = 1; i <= maxa; i++) {
  if (diff_b[i] && s.count(i)) s.erase(i), ans++;
 }

 set<int> repeat;
 for (auto i: s) {
  if (2 * i <= maxa && diff_b[2 * i] > 0) {
   repeat.insert (i); 
  }
 }
 cout << (int) repeat.size() << '\n';
 return 0;
}
