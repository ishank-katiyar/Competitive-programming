#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 map<long long int, int> mp;
 int n;
 cin >> n;
 vector<long long int> a(n + 1);
 for (int i = 1; i <= n; i++) cin >> a[i];
 mp[0] = 0;
 int ans = 0;
 long long int sum = 0;
 for (int i = 1; i <= n; i++) {
  sum += a[i];
  if (mp.count (sum)) {
   ans++;
   mp.clear();
   mp[0] = 0;
   sum = a[i];
   mp[sum] = i;
  }
  else mp[sum] = i;
 }
 cout << ans << '\n';
 return 0;
}
