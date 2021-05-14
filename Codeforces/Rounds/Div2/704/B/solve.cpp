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
  deque<int> a (n);
  map <int, int> mp;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   mp[a[i]] = i + 1;
  }
  vector<bool> used (n + 1, false);
  int sz = n;
  for (int i = n; i >= 1; i--) {
   if (used[i]) {
    continue;
   }
   int idx = mp[i];
   vector <int> nw;
   sz = static_cast <int> (a.size());
   for (int j = sz; j >= idx; j--) {
    nw.push_back (a[j - 1]);
    used[a[j - 1]] = true;
    a.pop_back();
   }
   reverse (nw.begin(), nw.end());
   for (auto& j: nw) cout << j << ' ';
  }
  assert (a.empty() == true);
  cout << '\n';
 }
 return 0;
}
