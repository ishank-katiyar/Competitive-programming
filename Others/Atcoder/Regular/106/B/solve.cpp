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

 // void do_dfs (int N, vector<int> comp) {
 //  covered.assign(n + 1, false);
 //  depth[N] = 0;
 //  dfs(N);
 // }

 void dfs (int N, vector<int> &comp) {
  if (covered[N] == true) return;
  comp.push_back(N);
  covered[N] = true;
  for (int i: adj[N]) {
   if (covered[i] == false) {
    dfs(i, comp);
   } 
  }
 }
};

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, m;
 cin >> n >> m;
 vector<long long> a(n);
 for (auto& i: a) cin >> i;
 vector<long long> b(n);
 for (auto& i: b) cin >> i;
 graph G(n);
 for (int i = 0; i < m; i++) {
  int x, y; 
  cin >> x >> y;
  G.add (x, y);
 }
 bool ok = true;
 for (int i = 1; i <= n; i++) {
  if (G.covered[i] == false) {
   vector<int> comp;
   G.dfs (i, comp);
   debug (comp);
   long long A = 0, B = 0;
   for (auto& I: comp) A += a[I - 1], B += b[I - 1];
   ok &= (A == B);
  }
 }
 cout << (ok ? "Yes" : "No") << '\n';
 return 0;
}
