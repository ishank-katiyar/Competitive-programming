#include <bits/stdc++.h>
using namespace std;

const int maxn = 110000;
vector<vector<int>> adj(maxn);
vector<int> cnt(maxn);
int ans = 0;
int n1, m;
vector<int> a(maxn);

void dfs(int n, int p) {
 if(a[n] == 1) cnt[n] += cnt[p] + 1;
 for(int& i: adj[n]) {
  if(i != p) dfs(i, n);
 }
}

void dfs1(int n, int p) {
 if((int) adj[n].size() == 1 && n != 1) ans++;
 for(int& i: adj[n]) {
  if(i != p && cnt[i] <= m) dfs1(i, n);
 }
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 cin >> n1 >> m;
 if(n1 == 1) {
  cout << 1 << '\n';
  return 0;
 }
 for(int i = 1; i <= n1; i++) {
  cin >> a[i];
 }
 for(int i = 1; i <= n1-1; i++) {
  int x, y;
  cin >> x >> y; 
  adj[x].push_back(y);
  adj[y].push_back(x);
 }
 dfs(1, 0);
 //for(int i = 1; i <= n1; i++) cout << cnt[i] << ' ';
 //cout << '\n';
 dfs1(1, 0);
 cout << ans << '\n';
 return 0;
}
