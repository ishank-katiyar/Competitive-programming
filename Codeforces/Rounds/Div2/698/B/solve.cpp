#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  int d;
  cin >> d;
  auto f = [] (int N, int D) -> bool {
   string s = to_string (N);
   for (auto& i: s) {
    if (string(1, i) == to_string (D)) return true;
   }
   return  false;
  };
  vector<int> a;
  for (int i = 1; i <= 100; i++) {
   if (f (i, d)) a.push_back (i);
  }
  int sz = static_cast <int> (a.size());
  vector<int> dp (101, false);
  for (int i = 1; i <= 100; i++) {
   if (f (i, d)) dp[i] = true;
   if (i > d && dp[i - d] == true) dp[i] = true;
   for (int j = 0; j < sz; j++) {
    if (i > a[j] && dp[i - a[j]] == true) dp[i] = true;
   }
  }
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   if (x > 100 || dp[x]) cout << "YES" << '\n';
   else cout << "NO" << '\n';
  }
 }
 return 0;
}
