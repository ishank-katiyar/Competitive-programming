#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
 int n;
 vector<int> Parent;
 vector<int> Size;
 explicit DSU (int N) {
  n = N;
  Parent.assign(n + 1, 0);
  Size.assign(n + 1, 0);
  make_set();
 }
 
 void make_set() {
  for(int i = 0; i <= n; i++) {
   Parent[i] = i;
   Size[i] = 1;
  }
 }
 
 int rep(int N) {
  if(Parent[N] == N) return N;
  return Parent[N] = rep(Parent[N]);
 }
 
 void Union(int A, int B) {
  int RA = rep(A);
  int RB = rep(B);
  if(RA != RB) {
   if(Size[RA] < Size[RB]) {
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
#ifndef LOCAL
 freopen ("socdist2.in", "r", stdin);
 freopen ("socdist2.out", "w", stdout);
#endif
 int n;
 cin >> n;
 vector<pair<int, int>> a (n);
 for (int i = 0; i < n; i++) {
  cin >> a[i].first >> a[i].second;
 }
 sort (a.begin(), a.end());
 int R = INT_MAX;
 for (int i = 1; i < n; i++) {
  if (a[i].second != a[i - 1].second) {
   R = min (R, a[i].first - a[i - 1].first);
  }
 }
 R--;
 DSU D (n);
 for (int i = 0; i < n; i++) {
  for (int j = i + 1; j < n; j++) {
   if (a[i].second == 1 && a[j].second == 1 && a[j].first - a[i].first <= R) D.Union (i, j);
  }
 }
 set <int> s;
 for (int i = 0; i < n; i++) {
  if (a[i].second == 1) {
   s.insert (D.rep (i));
  }
 }
 cout << static_cast <int> (s.size()) << '\n';
 return 0;
}
