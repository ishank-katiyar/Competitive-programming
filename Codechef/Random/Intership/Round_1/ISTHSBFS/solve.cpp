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
 vector<int> dist;
 vector<int> special;

 graph (int N) {
  n = N;
  adj.assign(n + 1, vector<int> ());
  degree.assign(n + 1, 0);
  depth.assign(n + 1, 0);
  dist.assign(n + 1, INT_MAX);
  covered.assign(n + 1, false);
 }

 void add (int X, int Y) {
  degree[X]++, degree[Y]++;
  edge.emplace_back(X, Y);
  adj[X].push_back(Y);
  adj[Y].push_back(X);
 }

 // void do_dfs (int N) {
 //  covered.assign(n + 1, false);
 //  depth[N] = 0;
 //  dfs(N);
 // }
 // 
 // void dfs (int N) {
 //  if (covered[N] == true) return;
 //  covered[N] = true;
 //  for (int i: adj[N]) {
 //   if (covered[i] == false) {
 //    depth[i] = depth[N] + 1;
 //    dfs(i);
 //   } 
 //  }
 // }
 
 void bfs () {
  queue<int> q;
  for (auto& i: special) dist[i] = 0, q.push (i), covered[i] = true;
  while (q.empty() == false) {
   int u = q.front();
   q.pop();
   for (auto& v: adj[u]) {
    if (covered[v] == false) {
     covered[v] = true;
     q.push (v);
     dist[v] = dist[u] + 1;
    }
   }
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
  int n, m, k;
  cin >> n >> m >> k;
  graph G (n);
  for (int i = 1; i <= m; i++) {
   int x, y; 
   cin >> x >> y;
   G.add (x, y);
  }
  for (int i = 1; i <= k; i++) {
   int x;
   cin >> x;
   G.special.push_back (x);
  }
  G.bfs();
  int q;
  cin >> q;
  while (q--) {
   int N;
   cin >> N;
   if (G.dist[N] == INT_MAX) cout << -1 << '\n';
   else cout << G.dist[N] << '\n';
  }
 }
 return 0;
}
