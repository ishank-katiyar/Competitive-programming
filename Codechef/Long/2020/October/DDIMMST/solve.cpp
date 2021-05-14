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
  for(int i = 0; i <= n; i++) Parent[i] = i, Size[i] = 1;
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
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, d;
 cin >> n >> d;
 vector<vector<int>> a(n, vector<int> (d));
 for (auto& i: a) for (auto& j: i) cin >> j;
 vector<pair<long long, pair<int, int> >> wei;
 for (int i = 0; i < n; i++) {
  for (int j = i + 1; j < n; j++) {
   long long int weigth = 0;
   for (int k = 0; k < d; k++) weigth += abs(a[i][k] - a[j][k]);
   wei.push_back(make_pair(-weigth, make_pair(i, j)));
  }
 }
 int sz = (int) wei.size();
 sort (wei.begin(), wei.end());
 DSU D(n);
 D.make_set();
 long long int ans = 0;
 for (int i = 0; i < sz; i++) {
  if (D.rep(wei[i].second.first) != D.rep(wei[i].second.second)) {
   ans += wei[i].first;
   D.Union(wei[i].second.first, wei[i].second.second);
  }
 }
 cout << -ans << '\n';
 return 0;
}
