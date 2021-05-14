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
  int m;
  cin >> m;
  vector<tuple<int, int, int>> a(n);
  for(auto& i: a) cin >> get<0>(i) >> get<1>(i) >> get<2>(i); 
  int mn = m, mx = m;
  bool ok = true;
  for(int i = 0; i < n; i++) {
   if(i == 0) mx = mx + get<0>(a[0]), mn = mn - get<0>(a[0]);
   else mx += (get<0>(a[i]) - get<0>(a[i-1])), mn -= (get<0>(a[i]) - get<0>(a[i-1]));
   int low = get<1>(a[i]);
   int high = get<2>(a[i]);
   if(mx < low || mn > high) {
    ok = false;
    break;
   }
   mx = min(mx, high);
   mn = max(mn, low);
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
