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
 }

 void do_dfs (int N) {
  covered.assign(n + 1, false);
  dfs(N);
 }

 void dfs (int N) {
  if (covered[N] == true) return;
  covered[N] = true;
  for (int i: adj[N]) {
   if (covered[i] == false) {
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
 vector<pair<int, int>> A;
 graph G(111);
 while (n--) {
  int type;
  cin >> type;
  if (type == 1) {
   int x, y;
   cin >> x >> y;
   A.emplace_back(x, y);
   int sz = (int) A.size();
   auto check = [&] (pair<int, int> a, pair<int, int> b) -> bool {
    return (a.first > b.first && a.first < b.second) || (a.second > b.first && a.second < b.second); 
   };
   for (int i = 0; i < sz - 1; i++) {
    if (check(A[i], A[sz - 1])) G.add(i + 1, sz); 
    if (check(A[sz - 1], A[i])) G.add(sz, i + 1); 
   }
  }
  else {
   int a, b;
   cin >> a >> b;
   G.do_dfs(a);
   cout << (G.covered[b] ? "YES" : "NO") << '\n';
  }
 }
 return 0;
}
