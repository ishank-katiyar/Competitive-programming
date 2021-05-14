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
  debug (X, Y);
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
};

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a (n);
  for (auto& i: a) cin >> i;
  vector<vector<int>> sorted;
  vector<int> cur(1, 1);
  sorted.push_back (cur);
  cur.clear();
  cur.push_back (a[1]);
  for (int i = 2; i < n; i++) {
   if (a[i] < a[i - 1]) {
    sorted.push_back (cur);
    cur.clear();
    cur.push_back (a[i]);
   }
   else cur.push_back (a[i]);
  }
  if (cur.empty() == false) sorted.push_back (cur);
  debug (sorted);
  reverse (a.begin(), a.end());
  graph G(n);
  int N = (int) sorted.size();
  for (int i = 1; i < N; i++) {
   for (auto& j: sorted[i]) {
    G.add (a.back(), j);
   }
   a.pop_back ();
  }
  for (int i = 1; i <= n; i++) {
   debug (i, G.adj[i]);
  }
  G.dfs(1);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max (ans, G.depth[i]);
  cout << ans << '\n';
 }
 return 0;
}
