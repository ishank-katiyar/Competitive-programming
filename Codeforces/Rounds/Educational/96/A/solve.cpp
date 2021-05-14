#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int t;
 cin >> t;
 map<int, vector<int>> ans;
 int maxn = 201;
 for (int i = 0; i < maxn; i++) {
  for (int j = 0; j < maxn; j++) {
   for (int k = 0; k < maxn; k++) {
    ans[i * 3 + j * 5 + k * 7] = {i, j, k};
   }
  } 
 }
 while (t--) {
  int n;
  cin >> n;
  if (ans.count (n)) {
   for (auto& i: ans[n]) cout << i << ' ';
   cout << '\n';
  }
  else cout << -1 << '\n';
 }
 return 0;
}
