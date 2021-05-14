#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int len = 100;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int TT;
  cin >> TT;
  for (int ttt = 1; ttt <= TT; ttt++) {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj (n + 1);
    map <pair<int64_t, int64_t>, pair<int64_t, int64_t>> mp;
    vector<int64_t> A;
    for (int i = 0; i < n - 1; i++) {
      int64_t x, y, l, a;
      cin >> x >> y >> l >> a;
      x--, y--;
      if (x > y) {
        swap (x, y);
      }
      mp[make_pair (x, y)] = make_pair (l, a);
      adj[x].push_back (y);
      adj[y].push_back (x);
      A.push_back (l);
    }
    sort (A.begin(), A.end());
    int szA = A.size();
    map <int64_t, int> idx_A;
    for (int i = 0; i < szA; i++) {
      idx_A[A[i]] = i;
    }
    map<int64_t, int> next_idx;
    for (auto& i: idx_A) {
      next_idx[i.first] = i.second;
    }
    assert ((int)mp.size() == n - 1);
    vector<int64_t> a (szA);
    vector<int64_t> b (n + 1);
    /*
     * n 
     * q
     * adj 
     * mp 
     * A 
     * szA 
     * idx_A 
     * next_idx 
     * a 
     * b 
     */
    auto get = [&] (const int l, const int r) -> int64_t {
      int64_t ret = 0;
      for (int i = l; i <= r; i++) {
        ret = __gcd (ret, a[i]);
      }
      return ret;
    };
    auto add = [&] (const int L, const int64_t value) {
      int idx_to_add = idx_A[L];
      a[idx_to_add] = value;
      while (idx_to_add % len != 0) {
        idx_to_add--;
      }
      b[idx_to_add / len] = __gcd (b[idx_to_add / len], value);
      // a.push_back (value);
      // int sz = a.size();
      // int szz = sz;
      // while (sz % len != 0) {
      //   sz--;
      // }
      // b[sz / len] = get (sz, szz - 1);
    };
    auto remove = [&] (const int L) {
      int last_added_idx = idx_A[L];
      a[last_added_idx] = 0;
      while (last_added_idx % len != 0) {
        last_added_idx--;
      }
      b[last_added_idx / len] = get (last_added_idx, last_added_idx + len - 1);
      // a.pop_back();
      // int sz = a.size();
      // int szz = sz;
      // while (sz % len != 0) {
      //   sz--;
      // }
      // b[sz / len] = get (sz, szz - 1);
    };
    auto query = [&] (int L) -> int64_t {
      // int l = idx_A[value].front(); 
      int64_t ret = 0;
      // int N = a.size();
      int l = 0, N = L;
      while (l <= N) {
        if (l % len == 0 && l + len - 1 < N) {
          ret = __gcd (ret, b[l / len]);
          l += len;
        } else {
          ret = __gcd (ret, a[l]);
          l += 1;
        }
      }
      return ret;
    };
    map<int, vector<pair<int, int64_t>>> que;
    for (int I = 0; I < q; I++) {
      int city, w;
      cin >> city >> w;
      city--;
      que[city].push_back (make_pair (I, w));
    }
    vector<int64_t> ans (q);
    // debug (adj);
    ordered_set X;
    vector<bool> used (n + 1, false);
    function <void(int, int)> dfs = [&] (int N, int P) {
      if (used[N] == true) {
        return;
      }
      used[N] = true;
      if (N != 0) {
        assert (mp.count (make_pair(min (N, P), max (N, P))));
        pair <int64_t, int64_t> pp = mp[make_pair(min (N, P), max (N, P))];
        X.insert (pp.first);
        add (pp.first, pp.second);
      }
      // debug (X.size());
      // for (auto i: X) {
      //   debug (i);
      // }
      debug (X);
      debug (a);
      for (auto& i: que[N]) {
        // debug (i);
        // debug (N + 1, X.order_of_key(i.second));
        debug ("query", N + 1, i.second);
        int idx1 = X.order_of_key(i.second + 1);
        idx1--;
        // int idx1 = X.order_of_key(i.second);
        if (idx1 < 0)  {
          continue;
        }
        int idx = idx_A [*X.find_by_order(idx1)];
        debug (N + 1, idx1, idx);
        ans[i.first] = query(idx);
        debug (i.first, ans[i.first]);
      }
      for (auto v: adj[N]) {
        // if (v != P) {
        //   dfs (v, N);
        // }
        if (used[v] == false) {
          dfs (v, N);
        }
      }
      if (N != 0) {
        assert (mp.count (make_pair(min (N, P), max (N, P))));
        pair <int64_t, int64_t> pp = mp[make_pair(min (N, P), max (N, P))];
        X.erase (pp.first);
        remove (pp.first);
      }
    };

    dfs (0, -1);

    cout << "Case #" << ttt << ": ";
    for (int i = 0; i < q; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
} 
