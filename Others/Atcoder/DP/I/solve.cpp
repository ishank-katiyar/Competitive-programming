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

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<double> a(n);
 for(double& i: a) cin >> i;
 vector<vector<double>> dp(n+1, vector<double> (n+1, 0.0));
 dp[0][0] = 1.0;
 for(int i = 1; i <= n; i++) {
  for(int j = 0; j <= i; j++) {
   dp[i][j] = dp[i-1][j] * (1.0 - a[i-1]) + (j ? dp[i-1][j-1] : 0.0) * a[i-1];
  }
 }
 debug(dp);
 double ans = 0;
 for(int i = n / 2 + 1; i <= n; i++) ans += dp[n][i];
 cout << fixed << setprecision(10) << ans << '\n';
 return 0;
}
