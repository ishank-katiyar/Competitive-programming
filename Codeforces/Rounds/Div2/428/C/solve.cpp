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
 vector<long double> prob;

 graph (int N) {
  n = N;
  adj.assign(n + 1, vector<int> ());
  degree.assign(n + 1, 0);
  depth.assign(n + 1, 0);
  covered.assign(n + 1, false);
  prob.assign(n + 1, 0);
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
  prob[1] = 1;
  dfs(N);
 }

 void dfs (int N) {
  if (covered[N] == true) return;
  covered[N] = true;
  for (int i: adj[N]) {
   if (covered[i] == false) {
    depth[i] = depth[N] + 1;
    prob[i] = prob[N] / (adj[N].size() - (N != 1));
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
 graph G(n);
 for (int i = 0; i < n - 1; i++) {
  int x, y;
  cin >> x >> y;
  G.add(x, y);
 }
 G.do_dfs(1);
 long double ans = 0.0;
 for (int i = 1; i <= n; i++) {
  if (G.degree[i] == 1) {
   ans += G.depth[i] * G.prob[i];
  }
 }
 cout << fixed << setprecision(7) << ans << '\n';
 return 0;
}
