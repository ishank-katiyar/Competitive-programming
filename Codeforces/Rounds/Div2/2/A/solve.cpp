#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<pair<string, int>> a(n);
 for(auto& i: a) cin >> i.first >> i.second;
 map<string, int> mp;
 for(int i = 0; i < n; i++) {
  mp[a[i].first] += a[i].second;
 }
 int mx = 0;
 for(auto& i: mp) mx = max(mx, i.second);
 map<string, int> mm;
 for(auto& i: mp) {
  if(i.second == mx) mm[i.first] = 1;
 }
 string ans = "";
 mp.clear();
 for(int i = 0; i < n; i++) {
  mp[a[i].first] += a[i].second;
  if(mp[a[i].first] >= mx && mm[a[i].first] == 1) {
   ans = a[i].first;
   break;
  }
 }
 cout << ans << '\n';
 return 0;
}
