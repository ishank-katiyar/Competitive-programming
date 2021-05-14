#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
  int n;
  vector<int> Parent;
  vector<int> Size;
  explicit DSU(int N) {
    n = N;
    Parent.assign(n + 1, 0);
    Size.assign(n + 1, 0);
    make_set();
  }

  void make_set() {
    for (int i = 0; i <= n; i++) {
      Parent[i] = i;
      Size[i] = 1;
    }
  }

  int rep(int N) {
    if (Parent[N] == N)
      return N;
    return Parent[N] = rep(Parent[N]);
  }

  void Union(int A, int B) {
    int RA = rep(A);
    int RB = rep(B);
    if (RA != RB) {
      if (Size[RA] < Size[RB]) {
        swap(RA, RB);
      }
      Parent[RB] = RA;
      Size[RA] += Size[RB];
    }
  }
};

struct EDGE {
  int u, v;
  int64_t wei;
  bool operator<(EDGE const &other) { return wei < other.wei; }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<EDGE> low, high;
    for (int i = 0; i < m; i++) {
      EDGE e;
      cin >> e.u >> e.v >> e.wei;
      if (e.wei <= k)
        low.push_back(e);
      else
        high.push_back(e);
    }
    sort(low.rbegin(), low.rend());
    sort(high.begin(), high.end());
    DSU D(n + 1);
    int total_edges = 0;
    int64_t ans1 = LLONG_MAX;
    int64_t ans = LLONG_MAX;
    for (auto &i : low) {
      if (D.rep(i.u) != D.rep(i.v)) {
        assert(i.wei <= k);
        ans1 = min(ans1, k - i.wei);
        total_edges++;
        if (total_edges == n - 1) {
          ans = min(ans, ans1);
        }
        D.Union(i.u, i.v);
      }
    }
    if (total_edges != n - 1) {
      int64_t cost = 0;
      for (auto &i : high) {
        if (D.rep(i.u) != D.rep(i.v)) {
          assert(i.wei > k);
          cost += i.wei - k;
          D.Union(i.u, i.v);
        }
      }
      ans = cost;
    } else {
      if (high.empty() == false) {
        ans = min(ans1, high[0].wei - k);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
