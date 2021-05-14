#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 string a;
 cin >> a;
 string b;
 cin >> b;
 int sa = (int) a.size();
 vector<vector<int>> c(sa, vector<int> (2, 0));
 c[0][0] = (a[0] == '0');
 c[0][1] = (a[0] == '1');
 for (int i = 1; i < sa; i++) {
  c[i][0] += c[i - 1][0] + (a[i] == '0');
  c[i][1] += c[i - 1][1] + (a[i] == '1');
 }
 long long ans = 0;
 int sb = (int) b.size();
 for (int i = 0; i < sb; i++) {
  int l = max (0, sa - (sb - i));
  int r = min (i, sa - 1);
  if (b[i] == '0') {
   int x = 0;
   if (l == 0) x = c[r][1];
   else x = c[r][1] - c[l - 1][1];
   ans += x;
  }
  else {
   int x = 0;
   if (l == 0) x = c[r][0];
   else x = c[r][0] - c[l - 1][0];
   ans += x;
  }
 }
 cout << ans << '\n';
 return 0;
}
