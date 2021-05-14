#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
#ifndef LOCAL
 freopen ("socdist1.in", "r", stdin);
 freopen ("socdist1.out", "w", stdout);
#endif
 int n;
 cin >> n;
 string s;
 cin >> s;
 int ans = 0;
 for (int i = 0; i < n; i++) {
  for (int j = i + 1; j < n; j++) {
   if (s[i] == '1') continue;
   if (s[j] == '1') continue;
   string S = s;
   S[i] = S[j] = '1';
   vector<int> a;
   for (int I = 0; I < n; I++) {
    if (S[I] == '1') a.push_back (I);
   }
   int cur_ans = INT_MAX;
   int sz = static_cast <int> (a.size());
   for (int I = 1; I < sz; I++) {
    cur_ans = min (cur_ans, a[I] - a[I - 1]);
   }
   assert (cur_ans != INT_MAX);
   ans = max (ans, cur_ans);
  }
 }
 cout << ans << '\n';
 return 0;
}
