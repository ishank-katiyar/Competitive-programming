#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int> (m));
  for(auto& i: a) for(auto& j: i) cin >> j;
  map<int, vector<pair<int, int>>> mp;
  for(int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    mp[i + j].emplace_back(i, j);
   }
  }
  int high = (int) mp.size() - 1;
  int low = 0;
  auto f = [&] (vector<pair<int, int>> &A, vector<pair<int, int>> &B) -> int {
   int c0 = 0, c1 = 0;
   for (auto& i: A) {
    if (a[i.first][i.second] == 1) c1++;
    else c0++;
   }
   for (auto& i: B) {
    if (a[i.first][i.second] == 1) c1++;
    else c0++;
   }
   return (int) A.size() + (int) B.size() - max(c0, c1);
  };
  int ans = 0;
  while (low < high) {
   ans += f(mp[low], mp[high]);
   low++;
   high--;
  }
  cout << ans << '\n';
 }
 return 0;
}
