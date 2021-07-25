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
 int n;
 cin >> n;
 vector<pair<int, pair<int, ll>>> a(n);
 for(int i = 0; i < n; i++) {
  cin >> a[i].second.first >> a[i].first >> a[i].second.second;
 }
 sort(a.begin(), a.end());
 vector<int> ee(n);
 for(int i = 0; i < n; i++) ee[i] = a[i].first;
 vector<ll> dp(n);
 for(int i = 0; i < n; i++) {
  int j = lower_bound(ee.begin(), ee.end(), a[i].second.first) - ee.begin();
  j--;
  if(j >= 0) dp[i] += dp[j];
  dp[i] += a[i].second.second;
  if(i > 0) dp[i] = max(dp[i], dp[i-1]);
 } 
 cout << dp[n-1] << '\n';
 return 0;
}
