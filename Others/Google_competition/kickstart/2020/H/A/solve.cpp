#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int test_case = 0;
 cin >> test_case;
 for (int ttt = 1; ttt <= test_case; ttt++) {
  cout << "Case #" << ttt << ": ";
  int n, k, s;
  cin >> n >> k >> s;
  int ans = (k - 1) + min (n + 1, k - s + (n - s + 1));
  cout << ans << '\n';
 }
 return 0;
}
