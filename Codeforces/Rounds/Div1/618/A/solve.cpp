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
 reverse(res.begin(), res.end());
 return res;
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

typedef long long int ll;

ll f(ll n) {
 //if (n == 0) return 1;
 ll temp = 1;
 while (temp <= (1LL << 32)) {
  n = n ^ temp;
  temp <<= 1;
 }
 return n;
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<ll> a(n);
 for (auto& i: a) cin >> i;
 if (n == 1) {
  cout << a[0] << '\n';
  return 0;
 }
 vector<ll> pre(n), suf(n);
 for (auto& i: a) {
  debug(bitset<31>(i), bitset<31> (f(i)));
  debug(i, f(i));
 }
 pre[0] = f(a[0]);
 for (int i = 1; i < n; i++) {
  pre[i] = pre[i-1] & f(a[i]);
 }
 suf[n-1] = f(a[n-1]);
 for (int i = n-2; i >= 0; i--) {
  suf[i] = suf[i+1] & f(a[i]);
 }
 vector<pair<ll, int>> ans(n);
 for (int i = 1; i < n - 1; i++) {
  ans[i].first = a[i] & pre[i - 1] & suf[i + 1];
  ans[i].second = i;
 }
 ans[0].first = a[0] & suf[1];
 ans[0].second = 0;
 ans[n-1].first = a[n - 1] & pre[n - 2];
 ans[n-1].second = n-1;
 sort(ans.rbegin(), ans.rend());
 debug(ans, pre, suf);
 cout << a[ans[0].second] << ' ';
  for (int i = 0; i < n; i++) {
   if (i != ans[0].second) cout << a[i] << ' ';
 }
 cout << '\n';
 return 0;
}
