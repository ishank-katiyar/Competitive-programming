#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, x;
 cin >> n >> x;
 string s;
 cin >> s;
 for (auto& i: s) {
  if (i == 'o') x++;
  else {
   x = max (0, x - 1);
  }
 }
 cout << x << '\n';
 return 0;
}
