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
  int64_t n, m;
  cin >> n >> m;
  vector <int64_t> a (n);
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   sum += a[i];
  }
  vector <pair<int64_t, int64_t>> pre (n);
  pre[0].first = a[0];
  pre[0].second = 1;
  for (int i = 1; i < n; i++) {
   pre[i].first += pre[i - 1].first + a[i];
   pre[i].second = i + 1;
  }
  sort (pre.begin(), pre.end(), [](const pair <int64_t, int64_t> A, const pair <int64_t, int64_t> B) -> bool {
   if (A.first != B.first) return A.first < B.first;
   return A.second < B.second;
  });

  vector<int64_t> sufindex (n);
  sufindex[n - 1] = pre[n - 1].second;
  for (int i = n - 2; i >= 0; i--) {
   sufindex[i] = min (sufindex[i + 1], pre[i].second);
  }

  vector<int64_t> pp (n);
  for (int i = 0; i < n; i++) {
   pp[i] = pre[i].first;
  }
  debug (pre, pp);
  for (int i = 0; i < m; i++) {
   int64_t x;
   cin >> x;

   if (x > pp.back()) {
    
    int64_t ans = 0;

    if (sum > 0) {
     
     x -= pp[n - 1];

     int64_t moves = (x / sum) + (x % sum != 0);

     ans += moves * n;

     x += pp[n - 1];
     x -= moves * sum;

     assert (x <= pp[n - 1]);

     if (x > 0) {
      int64_t idx = static_cast <int64_t> (lower_bound (pp.begin(), pp.end(), x) - pp.begin());
      debug (idx);
      assert (idx != n);
      ans += sufindex[idx] - 1;
     } else {
      ans -= 1;
     }
    } else {
     ans = -1;
    }
    cout << ans << ' ';
   } else {
    int64_t idx = static_cast <int64_t> (lower_bound (pp.begin(), pp.end(), x) - pp.begin());
    assert (idx != n);
    cout << sufindex[idx] - 1 << ' ';
   }
  }
  cout << '\n';
 }
 return 0;
}
