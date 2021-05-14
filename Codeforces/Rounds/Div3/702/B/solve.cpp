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
  vector<int> a (3);
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   a[x % 3]++;
  }
  int ans = 0;
  for (int i = 0; i < 100; i++) {
   if (a[i % 3] > n / 3) {
    ans += a[i % 3] - n / 3;
    a[(i + 1) % 3] += a[i % 3] - n / 3;
    a[i % 3] = n / 3;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
