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
  if (n == 1) {
   cout << 9 << '\n';
   continue;
  }
  cout << 98;
  n -= 2;
  int d = 9;
  // bool ok = false;
  while (n--) {
   cout << d; 
   // if (ok == true) {
   d += 1;
   if (d == 10) {
    d = 0;
   }
   //  if (d == 10) {
   //   d = 0;
   //   // ok = false;
   //  }
   // }
   // else {
   //  d -= 1;
   //  if (d == -1) {
   //   d = 9;
   //   // ok = true;
   //  }
   // }
  }
  cout << '\n';
 }
 return 0;
}
