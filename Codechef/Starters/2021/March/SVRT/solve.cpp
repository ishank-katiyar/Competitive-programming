#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  int dd = n / k + (n % k != 0);
  int cnt = n % k;
  if (cnt == 0) {
   cnt = k;
  }
  cout << dd << ' ' << cnt << '\n';
 }
 return 0;
}
