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
};

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 int m;
 cin >> m;
 graph G(n);
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 for (int i = 0; i < m; i++) {
  int x, y;
  cin >> x >> y;
  G.add(x, y);
 }
 vector<int> s(a.begin(), a.end());
 sort (s.begin(), s.end());
 for (int i = 0; i < n; i++) {
  int tt = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
  for (int u: G.adj[i + 1]) {
   if (a[u - 1] < a[i]) tt--;
  }
  assert (tt >= 0);
  cout << tt << ' ';
 }
 cout << '\n';
 return 0;
}
