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

typedef long long int ll;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, q;
 cin >> n >> q;
 vector<ll> a(n);
 for(auto& i: a) cin >> i;
 vector<int> c(n);
 for(int i = 0; i < q; i++) {
  int l, r;
  cin >> l >> r;
  l--, r--;
  c[l]++;
  if(r + 1 < n) c[r+1]--;
 }
 map<int, int> mp;
 int sum = 0;
 for(int i = 0; i < n; i++) {
  sum += c[i];
  mp[sum]++;
 }
 debug(mp);
 sort(a.rbegin(), a.rend());
 ll ans = 0;
 for(auto& i: mp) {
  int x = i.second;
  ll sum1 = 0;
  while(x--) sum1 += a.back(), a.pop_back();
  ans += i.first * sum1;
 }
 cout << ans << '\n';
 return 0;
}
