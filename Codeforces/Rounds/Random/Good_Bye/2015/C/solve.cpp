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
 int n, m;
 cin >> n >> m;
 vector<string> a(n);
 for (auto& i: a) cin >> i;
 vector<vector<int>> dp(n, vector<int> (m , 0));
 for (int i = 0; i < n; i++) {
  int cnt = 0;
  for (int j = 0; j < m; j++) {
   int ok = 2;
   if (i - 1 < 0 || a[i - 1][j] == '#') ok--;
   if (j - 1 < 0 || a[i][j - 1] == '#') ok--;
   if (a[i][j] == '#') ok = 0;
   cnt += ok;
   dp[i][j] += cnt + (i ? dp[i - 1][j] : 0); 
  }
 }
 vector<vector<int>> extra (n, vector<int> (m, 0));
 for (int j = 1; j < m; j++) {
  for (int i = 0; i < n; i++) {
   bool ok = true;
   if (a[i][j] == '#') ok = false;
   if (a[i][j - 1] == '#') ok = false;
   extra[i][j] += (i ? extra[i - 1][j] : 0) + ok;
  }     
 }
 vector<vector<int>> extra1 (n, vector<int> (m, 0));
 for (int i = 1; i < n; i++) {
  for (int j = 0; j < m; j++) {
   bool ok = true;
   if (a[i][j] == '#') ok = false;
   if (a[i - 1][j] == '#') ok = false;
   extra1[i][j] += (j ? extra1[i][j - 1] : 0) + ok;
  }     
 }
 int q;
 cin >> q;
 while (q--) {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--, y1--, x2--, y2--;
  int ans = dp[x2][y2];
  if (x1 > 0) ans -= dp[x1 - 1][y2];
  if (y1 > 0) ans -= dp[x2][y1 - 1];
  if (x1 > 0 && y1 > 0) ans += dp[x1 - 1][y1 - 1]; 
  if (x1 > 0) ans -= (extra[x2][y1] - extra[x1 - 1][y1]);
  else ans -= extra[x2][y1];
  if (y1 > 0) ans -= (extra1[x1][y2] - extra1[x1][y1 - 1]);
  else ans -= extra1[x1][y2];
  cout << ans << '\n';
 }
 return 0;
}
