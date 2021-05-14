#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m, k;
 cin >> n >> m >> k;
 vector<pair<int, int>> a(n);
 for (int i = 0; i < n; i++) {
  cin >> a[i].first;
  a[i].second = i;
 }
 sort (a.rbegin(), a.rend());
 vector<bool> A(n);
 long long int ans = 0;
 for (int i = 0; i < m * k; i++) {
  A[a[i].second] = true;
  ans += a[i].first;
 }
 int cnt = 0;
 vector<int> index;
 for (int i = 0; i < n; i++) {
  cnt += A[i];
  if (cnt == m) {
   index.push_back(i + 1);
   cnt = 0;
  }
 }
 index.pop_back();
 assert ((int) index.size() == k - 1);
 cout << ans << '\n';
 for (int& i: index) cout << i << ' ';
 cout << '\n';
 return 0;
}
