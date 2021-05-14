#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<long long int> a(n);
 for(auto& i: a) cin >> i;
 long long int ans = 0;
 long long int cur = a[0];
 for(int i = 1; i < n; i++) {
  if(a[i] < cur) ans += cur - a[i];
  cur = max(cur, a[i]);
 }
 
 cout << ans << '\n';
}
