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
 int t;
 cin >> t;
 while(t--) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  DSU A(n);
  A.make_set();
  for(int i = k; i < n; i++) {
   A.Union(i - k, i); 
  }
  for(int i = 0; i < n / 2; i++) {
   A.Union(i, n - i - 1);
  }
  map<int, vector<int>> mp;
  for(int i = 0; i < n; i++) {
   mp[A.rep(i)].push_back(i); 
  }
  auto f = [&](vector<int> &V) -> int {
   map<char, int> M;
   for(auto& ii: V) M[s[ii]]++;
   int mx = 0;
   for(auto& i: M) mx = max(mx, i.second);
   return (int) V.size() - mx;
  };
  int ans = 0;
  for(auto& i: mp) ans += f(i.second);
  cout << ans << '\n';
 }
 return 0;
}
