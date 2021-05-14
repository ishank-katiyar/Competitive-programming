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
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a (n + 1);
  for (int i = 1; i <= n; i++) {
   cin >> a[i];
  }
  sort (a.begin(), a.end());
  // debug (a);
  const int maxn = 300;
  vector<vector<long long int>> dp (maxn, vector<long long int> (n + 1, LLONG_MAX));
  // for (int i = 0; i <= n; i++) dp[0][i] = 0;
  // for (int i = 0; i <= maxn; i++) dp[i][0] = 0;
  for (int i = 1; i < maxn; i++) {
   for (int j = 1; j <= min (i, n); j++) {
    if (i == 1) {
     dp[1][j] = min (dp[i][j], (long long int) abs (i - a[j]));
    }
    if (j == 1) {
     dp[i][j] = min (dp[i][j], (long long int) abs (i - a[j]));
    }
    if (i > 1 && j > 1) {
     if (dp[i - 1][j - 1] == LLONG_MAX) {
      debug (i, j);
     }
     assert (dp[i - 1][j - 1] != LLONG_MAX);
     dp[i][j] = min (dp[i][j], dp[i - 1][j - 1] + (long long int) abs (i - a[j]));
    }
    if (i > 1 && j <= i - 1) {
     if (dp[i - 1][j] == LLONG_MAX) {
      debug (i, j);
     }
     assert (dp[i - 1][j] != LLONG_MAX);
     dp[i][j] = min (dp[i][j], dp[i - 1][j]);
    }
    // debug (i, j, dp[i][j]);
   }
  }
  // debug (dp);
  long long int ans = LLONG_MAX;
  for (int i = 1; i < maxn; i++) ans = min (ans, dp[i][n]);
  assert (ans != LLONG_MAX);
  cout << ans << '\n';
 }
 return 0;
}
