#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 1;
vector<set<int>> adj(maxn);
vector<int> comp;
vector<bool> used(maxn, false);

void dfs(int n) {
 if(used[n] == true) return;
 used[n] = true;
 comp.push_back(n);
 for(int i: adj[n]) {
  dfs(i);
 }
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m;
 cin >> n >> m;
 while(m--) {
  int x, y; 
  cin >> x >> y;
  adj[x].insert(y);
  adj[y].insert(x);
 }
 int ans = 0;
 for(int i = 1; i <= n; i++) {
  if(used[i] == false) {
   dfs(i);
   ans = max(ans, (int) comp.size());
   comp.clear();
  }
 }
 cout << ans << '\n';
 return 0;
}
