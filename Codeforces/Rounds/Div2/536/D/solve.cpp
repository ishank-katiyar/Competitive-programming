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
 vector<int> euler_path;

 graph (int N) {
  n = N;
  adj.assign(n + 1, set<int> ());
  degree.assign(n + 1, 0);
  depth.assign(n + 1, 0);
  covered.assign(n + 1, false);
 }

 void add (int X, int Y) {
  degree[X]++, degree[Y]++;
  edge.emplace_back(X, Y);
  adj[X].insert(Y);
  adj[Y].insert(X);
 }

 void bfs() {
  set<int> s;
  s.insert(1);
  covered[1] = true;
  while (s.empty() == false) {
   int tt = *(s.begin());
   s.erase(s.begin());
   euler_path.push_back(tt);
   for (int i: adj[tt]) {
    if (covered[i] == false) {
     s.insert(i);
     covered[i] = true;
    }
   }
  }
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
  G.add(x, y);
 }
 G.bfs();
 for (auto& i: G.euler_path) cout << i << ' ';
 cout << '\n';
 return 0;
}
