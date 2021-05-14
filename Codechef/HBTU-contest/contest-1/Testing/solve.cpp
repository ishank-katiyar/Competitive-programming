#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int x, y;
  cin >> x >> y;
  string s;
  cin >> s;
  int X = x, Y = y;
  for (auto& i: s) {
   if (i == 'N') Y++;
   if (i == 'S') Y--;
   if (i == 'E') X++;
   if (i == 'W') X--;
  }
  cout << fixed << setprecision(6) << static_cast<double> (s.size()) - static_cast <double> (sqrt (pow (abs (X - x), 2) + pow (abs (Y - y), 2))) << '\n';
 }
 return 0;
}
