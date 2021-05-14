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
 map<pair<int, int>, int> mp;

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
  mp[edge.back()]++;
  adj[X].push_back(Y);
  adj[Y].push_back(X);
 }

 bool check(int x, int y) {
  if (x > y) swap(x, y);
  return mp.count(make_pair(x, y));
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
  if (x > y) swap(x, y);
  G.add(x, y);
 }
 int ans = 1e9;
 for (auto& i: G.edge) {
  for (int j = 1; j <= n; j++) {
   int x = j, y = i.first;
   int z = i.second;
   if (G.check(x, y) && G.check(x, z)) {
    int value = G.adj[x].size() + G.adj[y].size() + G.adj[z].size() - 6;
    ans = min (ans, value);
   }
  }
 }
 cout << (ans == 1e9 ? -1 : ans) << '\n';
 return 0;
}
