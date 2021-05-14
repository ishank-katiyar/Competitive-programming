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

 void dfs (int N, vector<int> &com) {
  if (covered[N] == true) return;
  covered[N] = true;
  com.push_back(N);
  for (int i: adj[N]) {
   if (covered[i] == false) {
    dfs(i, com);
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
 bool ok = true;
 for (int i = 1; i <= n; i++) {
  if (G.covered[i] == false) {
   vector<int> com;
   G.dfs(i, com);
   int sz = (int) com.size();
   bool cur = true;
   for (auto& I: com) {
    cur &= (G.degree[I] == sz - 1); 
   }
   ok &= cur;
  }
 }
 cout << (ok ? "YES" : "NO") << '\n';
 return 0;
}
