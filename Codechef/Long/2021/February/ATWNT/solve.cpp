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

 explicit graph (int N) {
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
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 int n;
 cin >> n;

 graph G (n + 1);

 for (int i = 0; i < n - 1; i++) {
  int x;
  cin >> x;
  G.add (x, i + 2);
 }

 vector <vector<pair<int, int>>> task(n + 1);

 vector<pair<int, int>> Q;

 int q;
 cin >> q;

 for (int i = 0; i < q; i++) {
  int v, w;
  cin >> v >> w;
  Q.emplace_back (v, w);
  task[v].emplace_back (w, i + 1);
 }

 vector<int> ans (q + 1, 0);

 queue<int> qq;
 vector<bool> used (n + 1, false);

 qq.push(1);
 used[1] = true;

 while (qq.empty() == false) {
  int v = qq.front();
  qq.pop();

  int sizeChild = static_cast <int> (G.adj[v].size()) - (v != 1);
  vector<pair<int, int>> new_task;

  for (auto &i: task[v]) {
   if (sizeChild == 0) {
    ans[i.second] += i.first;
   } else {
    if (i.first % sizeChild == 0) {
     new_task.emplace_back (i.first / sizeChild, i.second);
    }
   }
  }

  task[v].clear();

  for (auto &i: G.adj[v]) {
   if (used[i] == true) {
    continue;
   }
   used[i] = true;
   qq.push(i);

   for (auto &j: new_task) {
    task[i].push_back (j);
   }

  }
 }

 for (int i = 0; i < q; i++) {
  cout << Q[i].second - ans[i + 1] << '\n';
 }
 return 0;
}
