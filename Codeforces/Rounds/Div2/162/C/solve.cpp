#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m;
 cin >> n >> m;
 cout << min(n, m) + 1 << '\n';
 int x = min(n, m), y = 0;
 while (x >= 0) {
  cout << x << ' ' << y << '\n';
  x--, y++;
 }
 return 0;
}
