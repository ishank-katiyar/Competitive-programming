#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 while (cin >> n) {
  int ans = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   if (x == -1) {
    if (sum == 0) ans++;
    else sum--;
   }
   else sum += x;
  }
  cout << ans << '\n';
 }
 return 0;
}
