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
  vector<string> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  vector<int> ans (10);

  auto f = [&] () {
   vector<set<int>> col (10);
   for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
     col[int (a[i][j] - '0')].insert (i);
    }
   }
   for (int i = 0; i < n; i++) {
    vector<set<int>> row (10);
    for (int j = 0; j < n; j++) {
     row[int (a[i][j] - '0')].insert (j);
    }
    for (int j = 0; j < n; j++) {
     int x = int (a[i][j] - '0');
     int L = max (j, n - j - 1);
     int bb = *col[x].begin();
     int ee = *(--col[x].end());
     int H = max (abs (bb - i), abs (ee - i));
     ans [x] = max (ans[x], L * H);
     bb = *row[x].begin();
     ee = *(--row[x].end());
     L = max (abs (bb - j), abs (ee - j));
     H = max (i, n - i - 1);
     ans [x] = max (ans[x], L * H);
    }
   }
  };
  f ();
  for (int i = 0; i < n; i++) {
   for (int j = i; j < n; j++) {
    swap (a[i][j], a[j][i]);
   }
  }
  f ();
  for (int i = 0; i < 10; i++) cout << ans[i] << ' ';
  cout << '\n';
 }
 return 0;
}
