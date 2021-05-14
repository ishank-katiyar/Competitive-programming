#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m, K;
  cin >> n >> m >> K;
  vector<string> s (n);
  for (int i = 0; i < n; i++) {
   cin >> s[i];
  }

  vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));

  for (int i = 1; i <= n; i++) {
   int sum = 0;
   for (int j = 1; j <= m; j++) {
    if (s[i - 1][j - 1] == '1') {
     sum += 1;
    }
    dp[i][j] = sum + dp[i - 1][j];
   }
  }

  auto f1 = [&] (int x, int y, int x1, int y1) -> int {
   return dp[x1][y1] - dp[x1][y - 1] - dp[x - 1][y1] + dp[x - 1][y - 1];
  };

  auto f = [&] (int S) -> bool {
   for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
     if (i - S + 1 >= 1 && j - S + 1 >= 1) {
      int cnt1 = f1 (i - S + 1, j - S + 1, i, j);
      int restcnt = n * m - dp[n][m] - (S * S - cnt1);
      if (cnt1 <= restcnt && cnt1 <= K) {
       return true;
      }
     }
    }
   }
   return false;
  };

  int low = 1, high = min (n, m);

  while (low < high) {
   int mid = (low + high) / 2;
   if (f (mid)) low = mid + 1;
   else {
    high = mid;
   }
  }

  if (f (low) == false) low--;

  assert (f (low) == true);

  cout << low << '\n';
 }
 return 0;
}
