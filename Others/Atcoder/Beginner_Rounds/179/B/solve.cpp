#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 bool ok = false;
 int cnt = 0;
 while (n--) {
  int x, y;
  cin >> x >> y;
  if (x == y) cnt++;
  else cnt = 0;
  if (cnt >= 3) ok = true;
 }
 cout << (ok ? "Yes" : "No") << '\n';
 return 0;
}
