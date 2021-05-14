#include <bits/stdc++.h>

using namespace std;

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char *ch) { return to_string((string)ch); }

string to_string(char ch) { return (string) "'" + ch + (string) "'"; }

string to_string(bool b) { return (b ? "true" : "false"); }

template <class A, class B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <class A> string to_string(A a) {
  string res = "{";
  bool first = true;
  for (const auto &x : a) {
    if (first == false)
      res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug() { cerr << "]\n"; }

template <class H, class... T> void debug(H head, T... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

#ifdef LOCAL
#define debug(...)                                                             \
  cerr << "[" << #__VA_ARGS__ << " ] = [";                                     \
  debug(__VA_ARGS__);
#else
#define debug(...)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    if (count(s.begin(), s.end(), '1') == n) {
      cout << n << '\n';
      continue;
    }
    vector<int> idx_1(n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1')
        idx_1[i] = i;
      else
        idx_1[i] = idx_1[i + 1];
    }
    auto index = [&](const int i, const int j) -> int {
      int ret = idx_1[i];
      assert(ret <= j);
      return ret - i;
    };
    int ans = 0;
    ans += (find(s.begin(), s.end(), '0') != s.end()) +
           (find(s.begin(), s.end(), '1') != s.end());
    for (int len = 2; len <= n; len++) {
      int cnt_0 = 0;
      set<int> index_1;
      int even = 0;
      int odd = 0;
      deque<int> c0, c1;
      int cc0 = 0, cc1 = 0;
      map<int, set<int>> mp;

      // Precompute for every length {{{
      if (s[0] == '1') {
        c0.push_back(0);
      }
      for (int i = 0; i <= len - 1; i++) {
        if (s[i] == '0') {
          if (cc1 > 0)
            c1.push_back(cc1);
          cc1 = 0;
          cc0++;
        } else {
          if (cc0 > 0 && c1.empty() == false && c1.back() % 2 == 0 &&
              c0.empty() == false)
            c0.back() += cc0;
          else if (cc0 > 0)
            c0.push_back(cc0);
          cc0 = 0;
          cc1++;
        }
      }
      if (cc1 > 0)
        c1.push_back(cc1);
      if (cc0 > 0) {
        if (c1.empty() == false && c1.back() % 2 == 0 && c0.empty() == false)
          c0.back() += cc0;
        else
          c0.push_back(cc0);
      }
      int sz = (int)c0.size();
      for (int i = 0; i < sz; i++) {
        if (i % 2 == 1)
          even += c0[i];
        else
          odd += c0[i];
      }
      cc1 = accumulate(c1.begin(), c1.end(), 0);
      cc0 = accumulate(c0.begin(), c0.end(), 0);
      if (cc1 == len && cc1 % 2 == 0)
        c0.clear();
      if (cc0 == len) {
        assert(cc1 == 0);
        cnt_0++;
      } else if (cc1 == 1) {
        index_1.insert(index(0, 0 + len - 1));
      } else if (cc1 > 1) {
        mp[cc1].insert(even);
      } else {
        assert(false);
      }
      // }}}

      debug(cc1, cc0, odd, even, c1, c0);
      // take care of cc1, cc0, odd, even, c1, c0
      // cc1
      // cc0
      // c1
      // c0
      // odd
      // even
      for (int i = 1; i < n; i++) {
        if (i + len - 1 >= n)
          continue;

        // Remove element {{{
        if (s[i] == '1') {
          if (s[i - 1] == '1') {
            // cc1
            cc1--;
            // cc0
            // c1
            c1.front()--;
            // c0 // odd // even
            if (c1.front() % 2 == 0) {
              assert(c0.front() == 0);
              c0.pop_front();
              swap(odd, even);
            } else {
              c0.push_front(0);
              swap(odd, even);
            }
          } else {
            // cc1
            // cc0
            cc0--;
            // c1
            // c0
            c0.front()--;
            if (cc1 == len - 1 && cc1 % 2 == 0) {
              assert((int)c0.size() == 1 && c0.front() == 0);
              c0.pop_front();
            }
            // odd
            odd--;
            // even
            if (cc1 == len - 1 && cc1 % 2 == 0) {
              assert(odd == 0 && even == 0);
            }
          }
        } else {
          if (s[i - 1] == '1') {
            // cc1
            cc1--;
            // cc0
            // c1
            assert(c1.front() == 1);
            c1.pop_front();
            // c0
            assert(c0.front() == 0);
            c0.pop_front();
            // odd // even
            swap(odd, even);
          } else {
            // cc1
            // cc0
            cc0--;
            // c1
            // c0
            c0.front()--;
            assert(c0.front() >= 0);
            // odd
            odd--;
            // even
          }
        }
        // }}}

        // Adding element {{{
        if (s[i + len - 2] == '0') {
          if (s[i + len - 1] == '0') {
            // cc1
            // cc0
            cc0++;
            // c1
            // c0
            c0.back()++;
            // odd // even
            if ((int)c0.size() % 2 == 0)
              even++;
            else
              odd++;
          } else {
            // cc1
            cc1++;
            // cc0
            // c1
            c1.push_back(1);
            // c0
            // odd
            // even
          }
        } else {
          if (s[i + len - 1] == '0') {
            // cc1
            // cc0
            cc0++;
            // c1
            // c0
            if (c1.back() % 2 == 0 && c0.empty() == false) {
              c0.back()++;
              // odd // even
              if ((int)c0.size() % 2 == 0)
                even++;
              else
                odd++;
            } else {
              c0.push_back(1);
              // odd // even
              if ((int)c0.size() % 2 == 0)
                even++;
              else
                odd++;
            }
          } else {
            // cc1
            cc1++;
            // cc0
            // c1
            c1.back()++;
            // c0
            if (c1.back() == len) {
              if (c1.back() % 2 == 0) {
                assert((int)c0.size() == 1 && c0.front() == 0);
                c0.pop_front();
                // odd // even
                assert(odd == 0 && even == 0);
              } else {
                debug("HERE");
                debug(i);
                debug(cc1);
                debug(cc0);
                debug(odd);
                debug(even);
                debug(c1);
                debug(c0);
                assert(c0.empty() == true);
                c0.push_front(0);
                // odd // even
                assert(odd == 0 && even == 0);
              }
            }
          }
        }
        // }}}

        if (cc1 == 0) {
          assert(cc0 == len);
          cnt_0++;
        } else if (cc1 == 1) {
          index_1.insert(index(i, i + len - 1));
        } else if (cc1 > 1) {
          mp[cc1].insert(even);
        } else {
          assert(false);
        }
      }
      // update ans here:
      int cur_ans = 0;
      if (cnt_0 > 0)
        cur_ans++;
      cur_ans += (int)index_1.size();
      for (auto i : mp) {
        debug(i.first, i.second);
      }
      for (auto &i : mp)
        cur_ans += (int)i.second.size();
      debug(len, cur_ans);
      ans += cur_ans;
    }
    cout << ans << '\n';
  }
  return 0;
}
