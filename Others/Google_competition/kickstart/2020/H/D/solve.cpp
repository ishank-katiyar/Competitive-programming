#include <bits/stdc++.h>

using namespace std;

class graph {
public:
 int n;
 vector<set<int>> adj;
 vector<int> degree;
 vector<pair<int, int>> edge;
 vector<int> depth;
 vector<bool> covered;
 vector<vector<int>> dist;

 graph (int N) {
  n = N;
  adj.assign(n + 1, set<int> ());
  degree.assign(n + 1, 0);
  depth.assign(n + 1, 0);
   covered.assign(n + 1, false);
   dist.assign (n + 1, vector<int> (n + 1, INT_MAX));
 }

 void add (int X, int Y) {
  degree[X]++, degree[Y]++;
  edge.emplace_back(X, Y);
  adj[X].insert(Y);
  adj[Y].insert(X);
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
 void APSP () {
  for (int u = 1; u <= n; u++) {
   covered.assign (n + 1, false);
   queue <int> q;
   q.push (u);
   dist[u][u] = 0;
   covered[u] = true;
   while (q.empty() == false) {
    int U = q.front();
    q.pop();
    for (auto V: adj[U]) {
     if (covered[V] == false) {
      q.push (V);
      covered[V] = true;
      dist[u][V] = min (dist[u][U] + 1, dist[u][V]);
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
 int test_case = 0;
 cin >> test_case;
 for (int ttt = 1; ttt <= test_case; ttt++) {
  cout << "Case #" << ttt << ": ";
  int n, q;
  cin >> n >> q;
  vector<string> a (n);
  graph G (27);
  for (int i = 0; i < n; i++) {
   string s;
   cin >> s;
   set <char> ss (s.begin(), s.end());
   s = string (ss.begin(), ss.end());
   int sz = (int) s.size();
   for (int j = 0; j < sz; j++) {
    for (int k = j + 1; k < sz; k++) {
     int c1 = int (s[j] - 'A' + 1);
     int c2 = int (s[k] - 'A' + 1);
     assert (c1 != c2);
     G.add (c1, c2);
    }
   }
   a[i] = s;
  }
  // map <char, vector<int>> mp;
  G.APSP();
  while (q--) {
   int x, y;
   cin >> x >> y;
   x--, y--;
   string S1 = a[x];
   int sz1 = (int) S1.size();
   string S2 = a[y];
   int sz2 = (int) S2.size();
   int ans = INT_MAX;
   for (int i = 0; i < sz1; i++) {
    for (int j = 0; j < sz2; j++) {
     int c1 = int (S1[i] - 'A' + 1);
     int c2 = int (S2[j] - 'A' + 1);
     ans = min (ans, G.dist[c1][c2]);
    }
   }
   if (ans == INT_MAX) ans = -1;
   else ans += 2;
   cout << ans << ' ';
  }
  cout << '\n';
 }
 return 0;
}
