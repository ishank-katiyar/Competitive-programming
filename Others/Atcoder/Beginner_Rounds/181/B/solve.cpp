#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 
 auto f = [] (long long int n) -> long long {
  return (n * (n + 1)) / 2;
 };

 int n;
 cin >> n;
 long long ans = 0;
 for (int i = 0; i < n; i++) {
  long long a, b;
  cin >> a >> b;
  ans += f (b) - f (a - 1);
 }
 cout << ans << '\n';
 return 0;
}
