#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  // cout << s << '\n';
  
  auto f = [] (string S, int x, int y) -> bool {
   if (x == 0 && y == 0) return false;
   int xx = 0, yy = 0;
   for (auto& i: S) {
    int next_x = xx, next_y = yy;
    if (i == 'L') next_x--;
    if (i == 'R') next_x++;
    if (i == 'D') next_y--;
    if (i == 'U') next_y++;
    if (next_x == x && next_y == y) continue;
    xx = next_x, yy = next_y;
   }
   // cout << x << ' ' << y << ' ' << xx << ' ' << yy << '\n';
   if (xx == 0 && yy == 0) return true;
   return false;
  };

  int x = 0, y = 0;
  pair<int, int> ans = make_pair (0, 0);
  for (auto& i: s) {
   if (i == 'L') x--;
   if (i == 'R') x++;
   if (i == 'D') y--;
   if (i == 'U') y++;
   if (f (s, x, y) == true) ans = make_pair (x, y);
  }
  cout << ans.first << ' ' << ans.second << '\n';
 }
 return 0;
}
