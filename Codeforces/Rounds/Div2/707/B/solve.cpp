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

  vector<int> sum (n + 2);

  auto add = [&] (int L, int R) {
   sum[L] += 1; 
   sum[R + 1] -= 1;
  };

  for (int i = 1; i <= n; i++) {
   int x;
   cin >> x;

   if (x == 0) {
    continue;
   }

   int l = max (i - x + 1, 1);
   int r = i;
   add (l, r);
  }

  int ss = 0;
  for (int i = 1; i <= n; i++) {
   ss += sum[i];
   cout << (ss > 0 ? 1 : 0) << ' ';
  }

  cout << '\n';
 }
 return 0;
}
