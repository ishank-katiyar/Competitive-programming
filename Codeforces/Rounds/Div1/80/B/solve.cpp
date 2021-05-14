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

 vector<int> color;
 vector<int> CC;
 bool do_cycle (int N) {
  covered.assign(n + 1, false);
  color.assign(n + 1, 0);
  vector<int> comp;
  bool ret = cycle(N, -1, comp);
  if (ret == true) {
   reverse(CC.begin(), CC.end());
   while (CC[0] != CC.back()) CC.pop_back();
   CC.pop_back();
   covered.assign(n + 1, false);
   for (auto& i: CC) covered[i] = true;
  }
  else CC.clear();
  return ret;
 }
 
 bool cycle (int N, int p, vector<int> &comp) {
  color[N] = 1;
  covered[N] = true;
  comp.push_back(N);
  bool ret = false;
  for (int i: adj[N]) {
   if (i == p) continue;
   if (covered[i] == true && color[i] == 1 && CC.empty() == true) {
    comp.push_back(i);
    CC = comp;
    return true;
   }
   if (covered[i] == false) {
    assert (color[i] == 0);
    ret |= cycle(i, N, comp);
   }
  }
  comp.pop_back();
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
 graph G(n);
 for (int i = 0; i < m; i++) {
  int x, y;
  cin >> x >> y;
  G.add(x, y);
 }
 if (G.do_cycle(1) == false) {
  cout << "NO" << '\n';
  return 0;
 }
 debug(G.CC);
 assert (G.CC.size() > 2);
 bool ok = true;
 auto check = [&] (int N, int left, int right) -> bool {
  function<void(int nn, int pp, int &sum, int &cnt)> dfs = [&] (int nn, int pp, int &sum, int &cnt) -> void {
   if (G.covered[nn] == true) {
    cout << "NO" << '\n';
    exit(0);
   } 
   G.covered[nn] = true;
   cnt++;
   sum += G.degree[nn]; 
   for (auto& ii: G.adj[nn]) {
    if (ii != pp) dfs(ii, nn, sum, cnt);
   }
  };
  int sum = (int) G.adj[N].size() - 2;
  int cnt = 1;
  for (auto& i: G.adj[N]) {
   if (i != left && i != right) {
    dfs(i, N, sum, cnt);
   } 
  } 
  assert (sum % 2 == 0);
  sum /= 2;
  debug(N, cnt, sum);
  return cnt - 1 == sum;
 };
 int sz = (int) G.CC.size();
 int x, y;
 x = G.CC[sz - 1];
 y = G.CC[1];
 ok &= check(G.CC[0], x, y);
 x = G.CC[sz - 2];
 y = G.CC[0];
 ok &= check(G.CC.back(), x, y);
 for (int i = 1; i < sz - 1; i++) {
  x = G.CC[i - 1];
  y = G.CC[i + 1];
  ok &= check(G.CC[i], x, y);
 }
 for (int i = 1; i <= n; i++) {
   ok &= G.covered[i];
 }
 cout << (ok ? "FHTAGN!" : "NO") << '\n';
 return 0;
}
