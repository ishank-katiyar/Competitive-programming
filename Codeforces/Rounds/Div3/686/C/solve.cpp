#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> A (n);
  for (int i = 0; i < n; i++) {
   cin >> A[i];
  }
  if (n == 1) {
   cout << 0 << '\n';
   continue;
  }
  vector<int> a;
  for (int i = 1; i < n; i++) {
   if (A[i] != A[i - 1]) {
    a.push_back (A[i - 1]);
   }
  }
  a.push_back (A.back());
  n = (int) a.size();
  if (n == 1) {
   cout << 0 << '\n';
   continue;
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
   mp[a[i]].push_back (i);
  }
  int ans = INT_MAX;
  for (auto& i: mp) {
   int seg = (int) i.second.size();
   if (i.second[seg - 1] == n - 1) seg--;
   if (i.second[0] == 0) seg--;
   seg++;
   ans = min (ans, seg);
  }
  cout << ans << '\n';
 }
 return 0;
}
