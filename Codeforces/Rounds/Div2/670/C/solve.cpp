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
  covered.assign(n + 1, false);
  depth[N] = 0;
  dfs(N);
 }

 void dfs (int N) {
  if (covered[N] == true) return;
  covered[N] = true;
  for (int i: adj[N]) {
   if (covered[i] == false) {
    depth[i] = depth[N] + 1;
    dfs(i);
   } 
  }
 }

 vector<int> Centroid() {
         vector<int> centroid;
         vector<int> sz(n + 1);
         function<void (int, int)> dfs = [&](int u, int prev) {
                 sz[u] = 1;
                 bool is_centroid = true;
                 for (auto v : adj[u]) if (v != prev) {
                         dfs(v, u);
                         sz[u] += sz[v];
                         if (sz[v] > n / 2) is_centroid = false;
                 }
                 if (n - sz[u] > n / 2) is_centroid = false;
                 if (is_centroid) centroid.push_back(u);
         };
         dfs(1, -1);
         return centroid;
 }
};

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  graph G(n);
  for (int i = 0; i < n - 1; i++) {
   int x, y;
   cin >> x >> y;
   G.add(x, y);
  }
  vector<int> a  = G.Centroid();
  if ((int) a.size() == 1) {
   cout << G.edge[0].first << ' ' << G.edge[0].second << '\n';
   cout << G.edge[0].first << ' ' << G.edge[0].second << '\n';
  }
  else {
   int x = -1;
   for (int& i: G.adj[a[1]]) {
    if (i != a[0]) {
     x = i;
     break;
    }
   }
   cout << a[1] << ' ' << x << '\n';
   cout << a[0] << ' ' << x << '\n';
  }
 }
 return 0;
}
