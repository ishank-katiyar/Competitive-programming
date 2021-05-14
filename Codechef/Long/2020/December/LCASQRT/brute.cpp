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

    LCA(vector<vector<int>> &adj, int root = 1) {
        n = adj.size();
        height.resize(n + 10);
        first.resize(n + 10);
        euler.reserve(n * 2 + 10);
        visited.assign(n + 10, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4 + 10);
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
        if (left == -1) return right;
        if (right == -1) return left;
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
  int P;
  cin >> P;
  graph G (n);
  for (int i = 2; i <= n; i++) {
   int x;
   cin >> x;
   G.add (i, x);
  }

  LCA L (G.adj, 1);

  vector<int> c (n + 1);
  for (int i = 1; i <= n; i++) {
   cin >> c[i];
  }

  int total_cnt = 0;
  vector<int> ans = {-1};
  
  auto check = [&] (vector<int> a) {
   vector<int> cur_c (n + 1);
   for (int x = 1; x <= n; x++) {
    for (int i = 1; i <= n; i++) {
     for (int j = 1; j <= n; j++) {
      if (L.lca (i, j) == x) {
       (cur_c[x] += (a[i - 1] * a[j - 1])) %= P;
      }
     }
    }
   }
   for (int i = 1; i <= n; i++) cur_c[i] %= P;
   if (cur_c == c) {
    debug (a);
    total_cnt++;
    if ((int)ans.size() == 1 && ans[0] == -1) ans = a;
   }
  };
  
  function<void(vector<int>, int)> f = [&] (vector<int> a, int INDEX) {
   int N = (int) a.size();
   if (INDEX == N - 1) {
    for (int A = 0; A < P; A++) {
     a[INDEX] = A;
     check (a);
    }
    return;
   }
   for (int A = 0; A < P; A++) {
    a[INDEX] = A;
    f (a, INDEX + 1);
   }
  };

  f (vector<int> (n, 0), 0);
  
  cout << total_cnt << '\n';
  for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
