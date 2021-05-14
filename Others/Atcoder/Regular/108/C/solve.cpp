#include <bits/stdc++.h>

using namespace std;

class graph {
public:
 int n;
 vector<vector<pair<int, int>>> adj;
 vector<int> degree;
 vector<pair<int, int>> edge;
 vector<int> depth;
 vector<bool> covered;
 vector<set<int>> value;
 vector<int> ans;

 graph (int N) {
  n = N;
  adj.assign(n + 1, vector<pair<int, int>> ());
  value.assign (n + 1, set<int> ());
  degree.assign(n + 1, 0);
  depth.assign(n + 1, 0);
  covered.assign(n + 1, false);
  ans.assign (n + 1, -1);
 }

 void add (int X, int Y, int wei) {
  degree[X]++, degree[Y]++;
  edge.emplace_back(X, Y);
  value[X].insert (wei);
  value[Y].insert (wei);
  adj[X].emplace_back(Y, wei);
  adj[Y].emplace_back(X, wei);
 }

 // void do_dfs (int N) {
 //  covered.assign(n + 1, false);
 //  depth[N] = 0;
 //  dfs(N);
 // }

 // void dfs (int N) {
 //  if (covered[N] == true) return;
 //  covered[N] = true;
 //  if (value[N].empty() == true) {
 //   int aa = 1;
 //   set <int> ss;
 //   for (pair<int, int> i: adj[N]) {
 //    assert (ans[i.first] != -1);
 //    ss.insert (ans[i.first]);
 //   }
 //   for (auto& i: ss) {
 //    if (i == aa) aa++;
 //   }
 //   ans[N] = aa;
 //   return;
 //  }
 //  int vv = *value[N].begin();
 //  ans[N] = vv;
 //  for (pair<int, int> i: adj[N]) {
 //   if (covered[i.first] == false) {
 //    // depth[i.first] = depth[N] + 1;
 //    if (value[i.first].find (vv) != value[i.first].end()) {
 //     value[i.first].erase (vv);
 //    }
 //    // dfs(i.first);
 //   }
 //  }
 // }
 
 void bfs (int N) {
  ans[N] = 1;
  queue<int> q;
  q.push (N);
  covered[N] = 1;
  while (q.empty() == false) {
   int u = q.front();
   q.pop();
   for (pair<int, int> i: adj[u]) {
    int v = i.first;
    int w = i.second;
    if (covered[v] == false) {
     q.push(v);
     covered[v] = true;
     if (w == ans[u]) {
      if (w == 1) ans[v] = 2;
      else ans[v] = 1;
     }
     else {
      ans[v] = w;
     }
    }
   }
  }
 }
};

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, m;
 cin >> n >> m;
 graph G (n);
 for (int i = 1; i <= m; i++) {
  int x, y, wei;
  cin >> x >> y >> wei;
  G.add (x, y, wei);
 }
 G.bfs (1);
 // for (int i = 1; i <= n; i++) {
 //  if (G.covered[i] == false) {
 //   G.dfs (i);
 //  }
 // }
 for (int i = 1; i <= n; i++) {
  assert (G.ans[i] != -1);
 }
 // for (int i = 1; i <= n; i++) {
 //  for (auto& j: G.adj[i]) {
 //   assert (G.ans[i] != G.ans[j.first]);
 //  }
 // }
 for (int i = 1; i <= n; i++) {
  cout << G.ans[i] << '\n';
 }
 return 0;
}
