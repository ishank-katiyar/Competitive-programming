#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m;
 cin >> n >> m;
 vector<vector<int>> A(n, vector<int> (m));
 for (auto& i: A) for (auto& j: i) cin >> j;
 map<int, vector<int>> mA;
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   mA[i + j].push_back(A[i][j]);
  }
 }
 vector<vector<int>> B(n, vector<int> (m));
 for (auto& i: B) for (auto& j: i) cin >> j;
 map<int, vector<int>> mB;
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   mB[i + j].push_back(B[i][j]);
  }
 }
 
 auto check = [&] (vector<int> a, vector<int> b) -> bool {
  sort (a.begin(), a.end());
  sort (b.begin(), b.end());
  return a == b;
 };

 int sz = n + m - 2;
 bool ok = true;
 for (int i = 0; i <= sz; i++) {
  ok &= (check(mA[i], mB[i]));
 }
 cout << (ok ? "YES" : "NO") << '\n';
 return 0;
}
