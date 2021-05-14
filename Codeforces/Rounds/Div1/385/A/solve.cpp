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
    dfs(i, comp);
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
 int k;
 cin >> k;
 vector<int> c(k);
 map<int, int> mp;
 for (auto& i: c) cin >> i, mp[i]++;
 for (int i = 0; i < m; i++) {
  int x, y;
  cin >> x >> y;
  G.add(x, y);
 }
 vector<pair<int, int>> A;
 int sum_nodes = 0, sum_edges = 0;
 int ans = 0;
 for (int i = 1; i <= n; i++) {
  if (G.covered[i] == false) {
   vector<int> comp;
   G.dfs(i, comp);
   bool ok = false;
   int tt = 0;
   for (auto& j: comp) {
    if (mp[j]) ok = true;
    tt += G.degree[j]; 
   }
   assert (tt % 2 == 0);
   tt /= 2;
   if (ok) {
    int N = (int) comp.size();
    int tt_edges = N * (N - 1);
    tt_edges /= 2;
    ans += tt_edges - tt;
    A.emplace_back((int) comp.size(), tt_edges);
   }
   else {
    sum_nodes += (int) comp.size();
    sum_edges += tt;
   }
  }
 }
 assert ((int) A.size() == k);
 debug(A, ans);
 int ANS = 0;
 for (auto& i: A) {
  int tt_nodes = i.first + sum_nodes;
  int tt_edges = i.second + sum_edges;
  int mx_edges = (tt_nodes * (tt_nodes - 1)) / 2;
  int extra = mx_edges - tt_edges;
  debug(extra);
  ANS = max(ANS, ans + extra); 
 }
 cout << ANS << '\n';
 return 0;
}
