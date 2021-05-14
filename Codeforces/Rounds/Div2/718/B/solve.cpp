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

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> b;
    vector<multiset<int>> a (n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        a[i].insert (x);
        b.push_back (make_pair (x, i));
      }
    }
    sort (b.begin(), b.end());
    debug (b);
    vector<vector<int>> ans (n, vector<int> (m, -1));
    for (int i = 0; i < m; i++) {
      int x = b[i].first;
      int idx = b[i].second;
      ans[idx][i] = x;
      a[idx].erase (a[idx].find (x));
    }
    debug (ans);
    for (int i = 0; i < n; i++) {
      int j = 0;
      debug (i, a[i]);
      for (auto X: a[i]) {
        while (ans[i][j] != -1) {
          j += 1;
        }
        if (j == m) {
          break;
        }
        ans[i][j] = X; 
        j += 1;
      }
      debug (j);
      // assert (j == m);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        assert (ans[i][j] != -1);
        cout << ans[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
