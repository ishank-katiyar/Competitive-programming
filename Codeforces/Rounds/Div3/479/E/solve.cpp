#include <bits/stdc++.h>
using namespace std;

class graph {
public:
 int n;
 vector<vector<int>> adj;
 vector<int> degree;
 vector<pair<int, int>> edge;
 vector<int> depth;
 vector<bool> covered;

 graph (int N) {
  n = N;
  adj.assign(n + 1, vector<int> ());
  degree.assign(n + 1, 0);
  depth.assign(n + 1, 0);
  covered.assign(n + 1, false);
 }

 void add (int X, int Y) {
  degree[X]++, degree[Y]++;
  edge.emplace_back(X, Y);
  adj[X].push_back(Y);
  adj[Y].push_back(X);
 }

 void do_dfs (int N) {
 }

 void dfs (int N, bool &ok) {
  if (covered[N] == true) return;
  covered[N] = true;
  ok &= (degree[N] == 2);
  for (int i: adj[N]) {
   if (covered[i] == false) {
    depth[i] = depth[N] + 1;
    dfs(i, ok);
   } 
  }
 }
};

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m;
 cin >> n >> m;
 graph G(n);
 for (int i = 0; i < m; i++) {
  int x, y;
  cin >> x >> y;
  G.add(x, y);
 }
 int ans = 0;
 for (int i = 1; i <= n; i++) {
  if (G.covered[i] == false) {
   bool ok = true;
   G.dfs(i, ok);
   ans += ok;
  }
 }
 cout << ans << '\n';
 return 0;
}
