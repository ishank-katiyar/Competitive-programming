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
  color.assign(n + 1, 0);
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

 bool do_cycle (int N) {
  covered.assign(n + 1, false);
  color.assign(n + 1, 0);
  return cycle(N, -1);
 }
 bool cycle (int N, int p) {
  color[N] = 1;
  covered[N] = true;
  bool ret = false;
  for (int i: adj[N]) {
   if (i == p) continue;
   if (covered[i] == true && color[i] == 1) return true;
   if (covered[i] == false) {
    assert (color[i] == 0);
    ret |= cycle(i, N);
   }
  }
  color[N] = 2;
  return ret;
 }
};

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m;
 cin >> n >> m;
 //graph G(n);
 //for (int i = 0; i < m; i++) {
  //int x, y;
  //cin >> x >> y;
  //G.add(x, y); 
 //}
 //for (int i = 1; i <= n; i++) {
  //debug(i, G.do_cycle(i));
 //}
 vector<string> a(n);
 for(auto& i: a) cin >> i;
 vector<graph> G(26, graph(n * m));
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   if (i - 1 >= 0 && a[i-1][j] == a[i][j]) G[a[i][j] - 'A'].add(i + n * j, i - 1 + n * j);
   //if (i + 1 < n && a[i+1][j] == a[i][j]) G[a[i][j] - 'A'].add(i + n * j, i + 1 + n * j);
   if (j - 1 >= 0 && a[i][j-1] == a[i][j]) G[a[i][j] - 'A'].add(i + n * j, i + n * (j - 1));
   //if (j + 1 < m && a[i][j+1] == a[i][j]) G[a[i][j] - 'A'].add(i + n * j, i + n * (j + 1));
  }
 }
 bool ans = false;
 for (int I = 0; I < 26; I++) {
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    if (G[I].covered[i + n * j] == false) {
     ans |= G[I].do_cycle(i + n * j);
    } 
   }
  }
 } 
 cout << (ans ? "Yes" : "No") << '\n';
 return 0;
}
