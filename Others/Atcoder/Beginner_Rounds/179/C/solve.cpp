#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<int> C(n + 1, 0);
 for (int i = 1; i <= n; i++) {
  for (int j = i; j <= n; j += i) C[j]++;
 }
 //for (int i = 1; i < 10; i++) cout << C[i] << ' ';
 //cout << '\n';
 int ans = 0;
 for (int i = 1; i < n; i++) {
  ans += C[i];
 }
 cout << ans << '\n';
 return 0;
}
