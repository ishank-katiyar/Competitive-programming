#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 // auto f = [] (int n) -> bool {
 //  if (n == 1) return false;
 //  for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
 //  return true;
 // };
 while (t--) {
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 2 * n + 2; i <= 4 * n; i += 2) {
   // if (i % 2 == 0 && f(i / 2) == true) {
   //  ans.push_back (i);
   // }
   // if ((int) ans.size() == n) break;
   ans.push_back(i);
  }
  for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
