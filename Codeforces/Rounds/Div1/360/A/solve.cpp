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
 vector<int> color;

 graph (int N) {
  n = N;
  adj.assign(n + 1, vector<int> ());
  degree.assign(n + 1, 0);
  depth.assign(n + 1, 0);
  covered.assign(n + 1, false);
  color.assign(n + 1, -1);
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
 
 bool check_bipartite (int N_) {
  bool ok = true;
  queue<int> q;
  color[N_] = 0;
  q.push(N_);
  while (q.empty() == false) {
   int N = q.front();
   q.pop();
   for (int i: adj[N]) {
    if(color[i] == -1) {
     color[i] = color[N] ^ 1;
     q.push(i);
    }
    else {
     ok &= (color[i] != color[N]); 
    }
   }
  }
  return ok;
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
 for (int i = 1; i <= n; i++) {
  if (G.adj[i].empty() == false && G.color[i] == -1) {
   if (G.check_bipartite(i) == false) {
    cout << -1 << '\n';
    return 0;
   }  
   //else break;
  }
 } 
 vector<int> c0, c1;
 for (int i = 1; i <= n; i++) {
  if (G.color[i] == 1) c1.push_back(i);
  else if(G.color[i] == 0) c0.push_back(i);
 }
 assert(c1.empty() == false && c0.empty() == false);
 cout << (int) c1.size() << '\n';
 for (auto& i: c1) cout << i << ' ';
 cout << '\n';
 cout << (int) c0.size() << '\n';
 for (auto& i: c0) cout << i << ' ';
 cout << '\n';
 return 0;
}

