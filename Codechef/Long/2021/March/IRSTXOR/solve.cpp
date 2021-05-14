#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t C;
  cin >> C;
  int max_bit = 0;
  int64_t x = 1;
  while (x <= C) {
   max_bit += 1;
   x *= 2;
  }
  // cout << max_bit << '\n';
  int64_t A = 0, B = 0;
  bool ok = true;
  for (int i = max_bit - 1; i >= 0; i--) {
   if ((C >> i) & 1) {
    if (ok == true) {
     A += 1LL << i;
    } else {
     B += 1LL << i;
    }
    ok = false;
   } else {
    A += 1LL << i;
    B += 1LL << i;
   }
  }
  // cout << A << ' ' << B << '\n';
  cout << A * B << '\n';
 }
 return 0;
}
