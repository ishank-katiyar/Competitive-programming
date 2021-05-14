#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a (n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> b (n, vector<int> (n));
  for (int i = 0; i < n; i++) {
    int x = i, y = i;
    int d = a[i];
    int dd = d;
    b[x][y] = d;
    d--;
    while (d) {
      while (y - 1 >= 0 && b[x][y - 1] == 0) {
        y--;
        b[x][y] = dd;
        d--;
      }
      if (d == 0) {
        continue;
      }
      assert (x + 1 < n && b[x + 1][y] == 0);
      x += 1;
      b[x][y] = dd;
      d--;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << b[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
