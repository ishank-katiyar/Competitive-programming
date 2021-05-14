#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 int q;
 cin >> q;
 vector<vector<int>> a(n, vector<int> (3, 0));
 map<int, vector<pair<int, int>>> R, B, G;
 for (auto& i: a) for (auto& j: i) cin >> j;
 for (int i = 0; i < n; i++) {
  int r = a[i][0];
  int b = a[i][1];
  int g = a[i][2];
  R[r].emplace_back(b, g);
  B[b].emplace_back(r, g);
  G[g].emplace_back(r, b);
 }
 for (auto& i: R) {
  sort (i.second.begin(), i.second.end(), [] (const pair<int, int> A, const pair<int, int> b) -> bool {
   if (A.first == b.first) return A.second < b.second;
   return A.first < b.first;
  });
 }
 for (auto& i: B) {
  sort (i.second.begin(), i.second.end(), [] (const pair<int, int> A, const pair<int, int> b) -> bool {
   if (A.first == b.first) return A.second < b.second;
   return A.first < b.first;
  });
 }
 for (auto& i: G) {
  sort (i.second.begin(), i.second.end(), [] (const pair<int, int> A, const pair<int, int> b) -> bool {
   if (A.first == b.first) return A.second < b.second;
   return A.first < b.first;
  });
 }

 return 0;
}
