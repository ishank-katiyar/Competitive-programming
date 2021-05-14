#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int> (n));
  for(auto& i: a) for(auto& j: i) cin >> j;
  int ans = 0;
  for(int i = n-1; i >= 0; i--) {
   if(ans % 2 == 0) {
    if(a[0][i] != i+1) {
     ans++;
    }
   }
   else {
    if(a[i][0] != i+1) ans++;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
