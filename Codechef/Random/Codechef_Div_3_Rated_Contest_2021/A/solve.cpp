#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int M, H;
  cin >> M >> H;
  int x = M / (H * H);
  if (x <= 18) {
   cout << 1 << '\n';
  } else if (x > 18 && x <= 24) {
   cout << 2 << '\n';
  } else if (x > 24 && x <= 29) {
   cout << 3 << '\n';
  } else {
   cout << 4 << '\n';
  }
 }
 return 0;
}
