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
 int ans = 0;
 for(auto& i: a) cin >> i;
 for(int i = 0; i < n; i++) {
  for(int j = i; j < n; j++) {
   int cur = 0; 
   for(int k = 0; k < i; k++) if(a[k] == 1) cur++;
   for(int k = i; k <= j; k++) if(a[k] == 0) cur++;
   for(int k = j+1; k < n; k++) if(a[k] == 1) cur++;
   ans = max(ans, cur);
  }
 }
 cout << ans << '\n';
 return 0;
}
