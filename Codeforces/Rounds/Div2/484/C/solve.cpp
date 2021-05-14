#include <bits/stdc++.h>

using namespace std;

class graph {
public:
 int n;
 vector<vector<int>> adj;
 vector<int> degree;
 vector<pair<int, int>> edge;
 vector<int> siz;
 vector<bool> covered;

 graph (int N) {
  n = N;
  adj.assign(n + 1, vector<int> ());
  degree.assign(n + 1, 0);
  siz.assign(n + 1, 1);
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
  dfs(N);
 }

 void dfs (int N) {
  if (covered[N] == true) return;
  covered[N] = true;
  int sum = 0;
  for (int i: adj[N]) {
   if (covered[i] == false) {
    dfs(i);
    sum += siz[i];
   } 
  }
  siz[N] += sum;
 }
};

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 if (n % 2 == 1) {
  cout << -1 << '\n';
  return 0;
 }
 graph G(n);
 for (int i = 0; i < n - 1; i++) {
  int x, y;
  cin >> x >> y;
  G.add(x, y);
 }
 G.do_dfs(1);
 int ans = 0;
 for (int i = 2; i <= n; i++) ans += (G.siz[i] % 2 == 0);
 cout << ans << '\n';
 return 0;
}
