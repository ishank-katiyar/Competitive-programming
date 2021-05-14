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

struct LCA {
  vector<int> height, euler, first, segtree;
  vector<bool> visited;
  int n;

  LCA(vector<vector<int>> &adj, int root = 0) {
    n = adj.size();
    height.resize(n + 1);
    first.resize(n + 1);
    euler.reserve(n * 2 + 1);
    visited.assign(n + 1, false);
    dfs(adj, root);
    int m = euler.size();
    segtree.resize(m * 4 + 1);
    build(1, 0, m - 1);
  }

  void dfs(vector<vector<int>> &adj, int node, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
      if (!visited[to]) {
        dfs(adj, to, h + 1);
        euler.push_back(node);
      }
    }
  }

  void build(int node, int b, int e) {
    if (b == e) {
      segtree[node] = euler[b];
    } else {
      int mid = (b + e) / 2;
      build(node << 1, b, mid);
      build(node << 1 | 1, mid + 1, e);
      int l = segtree[node << 1], r = segtree[node << 1 | 1];
      segtree[node] = (height[l] < height[r]) ? l : r;
    }
  }

  int query(int node, int b, int e, int L, int R) {
    if (b > R || e < L)
      return -1;
    if (b >= L && e <= R)
      return segtree[node];
    int mid = (b + e) >> 1;

    int left = query(node << 1, b, mid, L, R);
    int right = query(node << 1 | 1, mid + 1, e, L, R);
    if (left == -1)
      return right;
    if (right == -1)
      return left;
    return height[left] < height[right] ? left : right;
  }

  int lca(int u, int v) {
    int left = first[u], right = first[v];
    if (left > right)
      swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
  }
};

class graph {
public:
  int n;
  vector<vector<pair<int, long long int>>> adj;
  vector<vector<int>> ADJ;
  vector<int> degree;
  vector<pair<int, int>> edge;
  vector<int> depth;
  vector<bool> covered;
  vector<int> parent;
  vector<long long> sum;

  graph(int N) {
    n = N;
    adj.assign(n + 1, vector<pair<int, long long int>>());
    ADJ.assign(n + 1, vector<int>());
    degree.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    sum.assign(n + 1, 0);
    covered.assign(n + 1, false);
  }

  void add(int X, int Y, int wei) {
    degree[X]++, degree[Y]++;
    edge.emplace_back(X, Y);
    ADJ[X].push_back(Y);
    ADJ[Y].push_back(X);
    adj[X].emplace_back(Y, wei);
    adj[Y].emplace_back(X, wei);
  }

  // void do_dfs(int N) {
  //   covered.assign(n + 1, false);
  //   depth[N] = 0;
  //   dfs(N);
  // }

  void dfs(int R) {
    if (covered[R] == true)
      return;
    covered[R] = true;
    for (auto i : adj[R]) {
      if (covered[i.first] == false) {
        parent[i.first] = R;
        sum[i.first] += sum[R] + i.second;
        dfs(i.first);
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    int R;
    cin >> R;
    graph G (n);
    for (int i = 1; i < n; i++) {
     int x, y;
     cin >> x >> y;
     int wei;
     cin >> wei;
     G.add (x, y, wei);
    }
    G.dfs (R);
    LCA L(G.ADJ, R);
    // for (int U = 1; U <= n; U++) {
    //  for (int V = U + 1; V <= n; V++) {
    //    int X = L.lca (U, V);
    //    debug ("lca", U, V, X);
    //  }
    // }
    // for (int i = 1; i <= n; i++) {
    //  debug ("parent", i, G.parent[i]);
    // }
    // for (int i = 1; i <= n; i++) {
    //  debug ("sum", i, G.sum[i]);
    // }
    while (q--) {
     int U, V;
     cin >> U >> V;
     int X = L.lca (U, V);
     long long ans = G.sum [U] + G.sum [V] - 2 * G.sum [X];
     cout << ans << '\n';
    }
  }
  return 0;
}
