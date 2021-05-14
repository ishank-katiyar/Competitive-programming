#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
 int n;
 vector<int> Parent;
 vector<int> Size;
 DSU (int N) {
  n = N;
  Parent.assign(n+1, 0);
  Size.assign(n+1, 0);
 }
 
 void make_set() {
  for (int i = 0; i <= n; i++) Parent[i] = i, Size[i] = 1;
 }
 
 int rep(int N) {
  if (Parent[N] == N) return N;
  return Parent[N] = rep(Parent[N]);
 }
 
 void Union(int A, int B) {
  int RA = rep(A);
  int RB = rep(B);
  if (RA != RB) {
   if (Size[RA] < Size[RB]) {
    swap(RA, RB);
   }
   Parent[RB] = RA;
   Size[RA] += Size[RB];
  }
 }
};

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  // {{{
  // int cnt = 0;
  // int cnt1 = 0;
  // int cnt2 = 0;
  // int X = -1;
  // for (auto& i: mp) {
  //  if ((int) i.second.size() > ((n + 1) / 2)) {
  //   cnt2++;
  //  }
  //  if ((int) i.second.size() == (n / 2)) {
  //   cnt1++;
  //   X = i.first;
  //  }
  //  if ((int) i.second.size() == (n / 2) + 1) {
  //   cnt1++;
  //   X = i.first;
  //  }
  //  cnt += ((int) i.second.size() < (n / 2));
  // }
  // if (cnt2 > 0) {
  //  cout << "NO" << '\n';
  //  continue;
  // }
  // vector<int> b;
  // if (cnt1 >= 1) {
  //  b = mp[X];
  //  mp.erase (mp.find (X));
  // }
  // auto it = mp.begin();
  // vector<int> ans(n);
  // for (int i = 0; i < n; i++) {
  //  if (i % 2 == 1) {
  //   ans[i] = it->second.back();
  //   it->second.pop_back();
  //   it++;
  //   if (it == mp.end()) it = mp.begin();
  //  }
  //  else {
  //   if (cnt1 >= 1) {
  //    ans[i] = b.back();
  //    b.pop_back();
  //   }
  //   else {
  //    ans[i] = it->second.back();
  //    it->second.pop_back();
  //    it++;
  //    if (it == mp.end()) it = mp.begin();
  //   }
  //  }
  // }
  // cout << "YES" << '\n';
  // for (int i = 0; i < n - 1; i++) {
  //  cout << ans[i] << ' ' << ans[i + 1] << '\n';
  // }
  // }}}
  vector<pair<int, int>> ans;
  DSU d(n);
  d.make_set();
  for (int i = 0; i < n; i++) {
   for (int j = i + 1; j < n; j++) {
    if (d.rep(i) != d.rep(j) && a[i] != a[j]) {
     ans.emplace_back(i + 1, j + 1);
     d.Union(i, j);
    }
   }
  }
  if ((int) ans.size() != n - 1) {
   cout << "NO" << '\n';
   continue;
  }
  cout << "YES" << '\n';
  for (auto& i: ans) cout << i.first << ' ' << i.second << '\n';
 }
 return 0;
}
