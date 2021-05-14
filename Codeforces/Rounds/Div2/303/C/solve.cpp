#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<pair<int, int>> a(n);
 for(auto& i: a) cin >> i.first >> i.second;
 int ans = 0;
 int x = - 1e9;
 for(int i = 0; i < n; i++) {
  if(x <= a[i].first - a[i].second) {
   x = a[i].first + 1;
   ans++;
   continue;
  }
  x = a[i].first + 1;
  if(i == n-1 || a[i].first + a[i].second < a[i+1].first) {
   x = a[i].first + a[i].second + 1;
   ans++;
  }
 }
 cout << ans << '\n';
 return 0;
}
