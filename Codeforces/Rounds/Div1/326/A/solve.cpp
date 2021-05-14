#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 2;
vector<int> c(maxn, 0);

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
  c[x]++;
 }
 int ans = 0;
 for (int i = 0; i < maxn; i++) {
  int x = c[i] / 2;
  c[i + 1] += x;
  if (c[i] % 2 == 1) ans++;
 }
 cout << ans << '\n';
 return 0;
}
