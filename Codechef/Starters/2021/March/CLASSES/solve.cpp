#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
 return '"' + s + '"';
}

string to_string(const char* ch) {
 return to_string((string)ch);
}

string to_string(char ch) {
 return (string)"'" + ch + (string)"'";
}

string to_string(bool b) {
 return (b ? "true" : "false");
}

template<class A, class B>
string to_string(pair<A, B> p) {
 return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class A>
string to_string(A a) {
 string res = "{";
 bool first = true;
 for(const auto& x: a) {
  if(first == false) res += ", ";
  first = false;
  res += to_string(x);
 }
 res += "}";
 return res;
}

void debug() {cerr << "]\n";}

template<class H, class... T>
void debug(H head, T... tail) {
 cerr << to_string(head) << " ";
 debug(tail...);
}

#ifdef LOCAL
 #define debug(...) cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else 
 #define debug(...) 
#endif

class graph {
public:
 int n;
 vector<vector<int>> adj;
 vector<int> degree;
 vector<pair<int, int>> edge;
 vector<int> depth;
 vector<bool> covered;
 vector<int> dist;

 graph (int N) {
  n = N;
  adj.assign(n + 1, vector<int> ());
  degree.assign(n + 1, 0);
  depth.assign(n + 1, 0);
  covered.assign(n + 1, false);
  dist.assign (n + 1, 0);
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

 void bfs () {
  queue <int> q;
  covered.assign (n + 1, false);
  covered[0] = true;
  q.push(0);
  dist[0] = 0;
  while (q.empty() == false) {
   int u = q.front();
   q.pop();
   for (auto& v: adj[u]) {
    if (covered[v] == false) {
     covered[v] = true;
     q.push (v);
     dist[v] = dist[u] + 1;
    }
   }
  }
 }
};

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m, s, k;
  cin >> n >> m >> s >> k;
  graph G (n);  
  for (int i = 0; i < m; i++) {
   int x, y;
   cin >> x >> y;
   G.add (x, y);
  }
  vector<int> A (s);
  for (int i = 0; i < s; i++) {
   cin >> A[i];
  }
  G.bfs();
  debug (G.dist);
  vector<int> dd;
  for (int i = 0; i < s; i++) {
   dd.push_back (G.dist[A[i]]);
  }
  sort (dd.begin(), dd.end());
  int64_t ans = 0;
  for (int i = 0; i < k; i++) {
   ans += 2 * dd[i];
  }
  cout << ans << '\n';
 }
 return 0;
}
