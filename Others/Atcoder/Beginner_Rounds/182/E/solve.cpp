#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int N, M, n, m;
 cin >> N >> M >> n >> m;
 vector<vector<int>> a (N + 1, vector<int> (M + 1));
 for (int i = 1; i <= n; i++) {
  int x, y;
  cin >> x >> y;
  a[x][y] = 1;
 }
 for (int i = 1; i <= m; i++) {
  int x, y;
  cin >> x >> y;
  assert (a[x][y] != 1);
  a[x][y] = 2;
 }
 int ans = 0;
 for (int i = 1; i <= N; i++) {
  bool ok = false;
  for (int j = 1; j <= M; j++) {
   if (a[i][j] == 1) {
    ok = true;
    continue;
   }
   if (a[i][j] == 2) {
    ok = false;
    continue;
   }
   if (a[i][j] == 0 && ok) {
    ans++;
    a[i][j] = 3;
   }
  }
  ok = false;
  for (int j = M; j >= 1; j--) {
   if (a[i][j] == 1) {
    ok = true;
    continue;
   }
   if (a[i][j] == 2) {
    ok = false;
    continue;
   }
   if (a[i][j] == 0 && ok) {
    ans++;
    a[i][j] = 3;
   }
  }
 }
 for (int j = 1; j <= M; j++) {
  bool ok = false;
  for (int i = 1; i <= N; i++) {
   if (a[i][j] == 1) {
    ok = true;
    continue;
   }
   if (a[i][j] == 2) {
    ok = false;
    continue;
   }
   if (a[i][j] == 0 && ok) {
    ans++;
    a[i][j] = 3;
   }
  }
  ok = false;
  for (int i = N; i >= 1; i--) {
   if (a[i][j] == 1) {
    ok = true;
    continue;
   }
   if (a[i][j] == 2) {
    ok = false;
    continue;
   }
   if (a[i][j] == 0 && ok) {
    ans++;
    a[i][j] = 3;
   }
  }
 }
 ans += n;
 cout << ans << '\n';
 return 0;
}
