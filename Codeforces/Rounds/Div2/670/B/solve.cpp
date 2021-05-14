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

typedef long long ll;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& i: a) cin >> i;
  vector<pair<ll, ll>> dp(n);
  dp[0] = make_pair(a[0], a[0]);
  for (int i = 1; i < n; i++) {
   dp[i].first = max(a[i], a[i]);
   dp[i].first = max(dp[i].first, dp[i - 1].first);
   dp[i].second = min(a[i], a[i]);
   dp[i].second = min(dp[i].second, dp[i - 1].second);
  }
  debug(dp);
  vector<pair<ll, ll>> dp1(n);
  dp1[1] = make_pair(a[0] * a[1], a[0] * a[1]);  
  for (int i = 2; i < n; i++) {
   dp1[i].first = max(dp[i - 1].first * a[i], dp[i - 1].second * a[i]);
   dp1[i].first = max(dp1[i].first, dp1[i - 1].first);
   dp1[i].second = min(dp[i - 1].first * a[i], dp[i - 1].second * a[i]);
   dp1[i].second = min(dp1[i].second, dp1[i - 1].second);
  }
  debug(dp1);
  vector<pair<ll, ll>> dp3(n);
  dp3[2] = make_pair(a[0] * a[1] * a[2], a[0] * a[1] * a[2]);
  for (int i = 3; i < n; i++) {
   dp3[i].first = max(dp1[i - 1].first * a[i], dp1[i - 1].second * a[i]);
   dp3[i].first = max(dp3[i].first, dp3[i - 1].first);
   dp3[i].second = min(dp1[i - 1].first * a[i], dp1[i - 1].second * a[i]);
   dp3[i].second = min(dp3[i].second, dp3[i - 1].second);
  }
  debug(dp3);
  vector<pair<ll, ll>> dp4(n);
  dp4[3] = make_pair(a[0] * a[1] * a[2] * a[3], a[0] * a[1] * a[2] * a[3]);
  for (int i = 4; i < n; i++) {
   dp4[i].first = max(dp3[i - 1].first * a[i], dp3[i - 1].second * a[i]);
   dp4[i].first = max(dp4[i].first, dp4[i - 1].first);
   dp4[i].second = min(dp3[i - 1].first * a[i], dp3[i - 1].second * a[i]);
   dp4[i].second = min(dp4[i].second, dp4[i - 1].second);
  }
  debug(dp3);
  vector<pair<ll, ll>> dp5(n);
  dp5[4] = make_pair(a[0] * a[1] * a[2] * a[3] * a[4], a[0] * a[1] * a[2] * a[3] * a[4]);
  for (int i = 5; i < n; i++) {
   dp5[i].first = max(dp4[i - 1].first * a[i], dp4[i - 1].second * a[i]);
   dp5[i].first = max(dp5[i].first, dp5[i - 1].first);
   dp5[i].second = min(dp4[i - 1].first * a[i], dp4[i - 1].second * a[i]);
   dp5[i].second = min(dp5[i].second, dp5[i - 1].second);
  }
  debug(dp3);
  cout << dp5[n - 1].first << '\n';
 }
 return 0;
}
