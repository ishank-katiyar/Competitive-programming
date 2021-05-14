#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 long long int T, S, q;
 cin >> T >> S >> q;
 int ans = 1;
 long long int real_time = S;
 for (int i = S + 1; i <= T; i++) {
  real_time++;
  while ((q * (i - S)) > ((q - 1) * real_time)) {
   ans++;
   real_time += i - 1;
  } 
 }
 cout << ans << '\n';
 return 0;
}
