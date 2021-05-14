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

    auto f = [](string S) -> string {
      int N = (int)S.size();
      int cnt_1 = count(S.begin(), S.end(), '1');
      if (cnt_1 <= 1)
        return S;
      vector<int> c1, c0;
      int cnt0 = 0, cnt1 = 0;
      if (S[0] == '1') {
        c0.push_back(0);
      }
      for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
          if (cnt1 > 0)
            c1.push_back(cnt1);
          cnt1 = 0;
          cnt0++;
        } else {
          if (cnt0 > 0 && c1.empty() == false && c1.back() % 2 == 0 &&
              c0.empty() == false)
            c0.back() += cnt0;
          else if (cnt0 > 0)
            c0.push_back(cnt0);
          cnt0 = 0;
          cnt1++;
        }
      }
      if (cnt1 > 0)
        c1.push_back(cnt1);
      if (cnt0 > 0) {
        if (c1.empty() == false && c1.back() % 2 == 0 && c0.empty() == false)
          c0.back() += cnt0;
        else
          c0.push_back(cnt0);
      }
      int sum = 0;
      int sz = (int)c0.size();
      for (int i = 1; i < sz; i += 2)
        sum += c0[i];
      string ret = string(cnt_1 - 1, '1') + string(sum, '0') + string(1, '1') +
                   string(N - cnt_1 - sum, '0');
      return ret;
    };

    map<string, int> mp;

    for (int len = 1; len <= n; len++) {
      for (int i = 0; i < n; i++) {
        if (i + len - 1 >= n)
          continue;
        debug(s.substr(i, len), f(s.substr(i, len)));
        mp[f(s.substr(i, len))]++;
      }
    }

    debug(mp);

    cout << (int)mp.size() << '\n';
  }
  return 0;
}
