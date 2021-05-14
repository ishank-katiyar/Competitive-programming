#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 for (auto& i: a) {
  cin >> i;
  if (i < 0) i *= -1;
 }
 sort (a.begin(), a.end());

 int j = 0;
 long long int ans = 0;
 for (int i = 0; i < n; i++) {
  while (j < n && a[j] <= 2 * a[i]) j++;
  ans += j - i - 1;
 }
 cout << ans << '\n';
 return 0;
}
