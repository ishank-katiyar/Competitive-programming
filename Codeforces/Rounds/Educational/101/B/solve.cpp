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
  int mx = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   sum += x;
   mx = max (mx, sum);
  }
  sum = 0;
  int mx1 = 0;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
   int x;
   cin >> x;
   sum += x;
   mx1 = max (mx1, sum);
  }
  cout << mx + mx1 << '\n';
 }
 return 0;
}
