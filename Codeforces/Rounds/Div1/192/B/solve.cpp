#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, m;
 cin >> n >> m;
 vector<string> a(n);
 int sx, sy;
 sx = sy = -1;
 int ex, ey;
 ex = ey = -1;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
  for (int j = 0; j < m; j++) {
   if (a[i][j] == 'S') {
    sx = i;
    sy = j;
   }
   if (a[i][j] == 'E') {
    ex = i;
    ey = j;
   }
  }
 }
 vector<vector<int>> dist (n + 1, vector<int> (m + 1, 0));
 vector<vector<bool>> used(n, vector<bool> (m, false));
 queue<pair<int, int>> q;
 q.push(make_pair(ex, ey));
 used[ex][ey] = true;
 dist[ex][ey] = 0;
 while (q.empty() == false) {
  pair<int, int> u = q.front();
  q.pop();
  assert (a[u.first][u.second] != 'T');
  vector<int> ax = {-1, 1, 0, 0};
  vector<int> ay = {0, 0, -1, 1};
  for (int i = 0; i < 4; i++) {
   if (u.first + ax[i] >= 0 && u.first + ax[i] < n && u.second + ay[i] >= 0 && u.second + ay[i] < m && used[u.first + ax[i]][u.second + ay[i]] == false && a[u.first + ax[i]][u.second + ay[i]] != 'T') {
    used[u.first + ax[i]][u.second + ay[i]] = true;
    q.push(make_pair(u.first + ax[i], u.second + ay[i]));
    dist[u.first + ax[i]][u.second + ay[i]] = dist[u.first][u.second] + 1;
   }
  }
 }
 //for (int i = 0; i < n; i++) {
  //for (int j = 0; j < m; j++) {
   //cerr << dist[i][j] << ' ';
  //}
  //cerr << endl;
 //}
 int mn = dist[sx][sy];
 assert (mn > 0);
 int cnt = 0;
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   if (a[i][j] >= '0' && a[i][j] <= '9' && dist[i][j] <= mn && used[i][j] == true) {
    int xx = int(a[i][j] - '0');
    cnt += xx;
   }
  }
 }
 cout << cnt << '\n';
 return 0;
}
