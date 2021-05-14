#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int last = 0;
  while (s.empty() == false && s.back() == 'L') s.pop_back(), last++;
  int first = 0;
  reverse (s.begin(), s.end());
  while (s.empty() == false && s.back() == 'L') s.pop_back(), first++;
  reverse (s.begin(), s.end());
  vector<int> a;
  int cur = 0;
  int ans = 0;
  n = (int) s.size();
  if (n == 0) {
   int Ans = 0;
   int mm = min (k, last);
   if (mm > 0) Ans++, mm--;
   Ans += 2 * mm;
   cout << Ans << '\n';
   continue;
  }
  for (int i = 0; i < n; i++) {
   if (s[i] == 'W') {
    if (cur > 0) a.push_back(cur);
    cur = 0;
    if (i > 0 && s[i - 1] == 'W') ans += 2;
    else ans += 1;
   } 
   else cur++;
  }
  //a.push_back(last);
  sort (a.begin(), a.end());
  int sz = (int) a.size();
  for (int i = 0; i < sz; i++) {
   if (k >= a[i]) {
    ans += 2 * a[i];
    k -= a[i];
    ans++;
   }
   else {
    ans += 2 * k;
    k = 0;
   }
  }
  int mn = min (k, last);
  ans += 2 * mn;
  k -= mn;
  last -= mn;
  mn = min (k , first);
  ans += 2 * mn;
  k -= mn;
  first -= mn;
  cout << ans << '\n';
 }
 return 0;
}
