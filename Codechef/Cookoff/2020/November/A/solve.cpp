#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, m, k;
 cin >> n >> m >> k;
 int ans = 0;
 for (int i = 0; i < n; i++) {
  long long sum = 0;
  for (int j = 0; j < k; j++) {
   int x;
   cin >> x;
   sum += x;
  }
  int qq;
  cin >> qq;
  if (qq <= 10 && sum >= m) ans++;
 }
 cout << ans << '\n';
 return 0;
}
