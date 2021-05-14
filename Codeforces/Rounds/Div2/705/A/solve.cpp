#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  if (n == 1) {
   cout << 0 << '\n' << '\n';
   continue;
  }
  if (n == k) {
   n--;
  }
  vector<int> ans({n});
  int prev = n;
  for (int i = n - 1; i >= 1; i--) {
   if (i == k) {
    continue;
   }
   if (i + prev > k) {
    ans.push_back (i);
   } else {
    break;
   }
   prev = i;
  }
  cout << static_cast <int> (ans.size()) << '\n';
  for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
