#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 while (cin >> n) {
  int ans = 0;
  while (n > 9) {
   int N = n;
   n = 0;
   while (N) n += N % 10, N /= 10;
   ans++;
  }
  cout << ans << '\n';
 }
 return 0;
}
