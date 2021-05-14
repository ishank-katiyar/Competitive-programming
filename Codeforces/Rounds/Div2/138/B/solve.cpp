#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 int k;
 cin >> k;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 int l = 0, r = -1;
 set<int> s;
 map<int, int> mp;
 for (int i = 0; i < n; i++) {
  s.insert (a[i]);
  mp[a[i]]++;
  if ((int) s.size() == k) {
   r = i;
   break;
  }
 }
 if (r == -1) {
  cout << "-1 -1\n";
  return 0;
 }
 for (int i = 0; i < n; i++) {
  mp[a[i]]--;
  if (mp[a[i]] == 0) {
   l = i;
   break;
  }
 }
 l++, r++;
 cout << l << ' ' << r << '\n';
 return 0;
}
