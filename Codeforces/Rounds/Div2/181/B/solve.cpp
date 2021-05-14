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

 void dfs (int N, vector<int> &comp) {
  if (covered[N] == true) return;
  covered[N] = true;
  comp.push_back(N);
  for (int i: adj[N]) {
   if (covered[i] == false) {
    depth[i] = depth[N] + 1;
    dfs(i, comp);
   } 
  }
 }
};

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n, m;
 cin >> n >> m;
 graph G(n);
 for (int i = 0; i < m; i++) {
  int x, y;
  cin >> x >> y;
  G.add (x, y);
 }
 map<int, vector<vector<int>>> mp;
 for (int i = 1; i <= n; i++) {
  if (G.covered[i] == false) {
   vector<int> comp;
   G.dfs(i, comp);
   int sz = (int) comp.size();
   if (sz > 3) {
    cout << -1 << '\n';
    return 0;
   }
   mp[sz].push_back(comp);
  }
 }
 if (mp[2].size() > mp[1].size()) {
  cout << -1 << '\n';
  return 0;
 }
 for (auto& i: mp[3]) {
  for (auto& j: i) cout << j << ' ';
  cout << '\n';
 }
 int sz = mp[2].size();
 for (int i = 0; i < sz; i++) {
  for (int j = 0; j < 2; j++) {
   cout << mp[2][i][j] << ' ';
  }
  cout << mp[1][i][0] << '\n';
 }
 //cerr << sz << endl;
 deque<int> d;
 //cerr << (int) mp[1].size() << endl;
 for (int i = sz; i < (int) mp[1].size(); i++) {
  d.push_back(mp[1][i][0]);
 }
 //cerr << (int) d.size() << endl;
 while (d.empty() == false) {
  cout << d.back() << ' ';
  d.pop_back();
  cout << d.back() << ' ';
  d.pop_back();
  cout << d.back() << '\n';
  d.pop_back();
 }
 return 0;
}
