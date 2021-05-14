#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t N;
  cin >> N;
  if (N <= 4) {
   int ans = 0;
   if (N == 1) {
    ans = 20;
   } else if (N == 2) {
    ans = 36;
   } else if (N == 3) {
    ans = 51;
   } else {
    ans = 60;
   }
   cout << ans << '\n';
   continue;
  }
  if (N % 4 == 0) {
   cout << (N) * (11) + 16;
  } else if (N % 4 == 1) {
   cout << (N - 1) * 11 + 20 + 12;
  } else if (N % 4 == 2) {
   cout << (N - 2) * 11 + 36 + 8; 
  } else {
   cout << (N - 3) * 11 + 51 + 4;
  }
  cout << '\n';
 }
 return 0;
}
