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
  int n, k;
  cin >> n >> k;
  vector<int> h (n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
   cin >> h[i];
   cnt += (h[i] >= k);
  }
  if (n == 1) {
   cout << -1 << '\n';
   continue;
  }
  if (cnt > 1) {
   cout << 2 << '\n';
   continue;
  }
  if (cnt == 1) {
   sort (h.rbegin(), h.rend());
   assert (h[0] >= k);
   h.erase (h.begin());
   assert (h[0] < k);
   n = static_cast <int> (h.size());
   int ans = 1;
   for (int i = 0; i < n; i++) {
    ans++;
    k -= h[i];
    if (k <= 0) break;
   }
   if (k > 0) ans = -1;
   cout << ans << '\n';
   continue;
  }
  assert (cnt == 0);
  vector<vector<int64_t>> dp (2 * k + 1, vector<int64_t> (2 * k + 1, INT_MAX));
  dp[0][0] = 0;
  for (int a = 0; a < n; a++) {
   for (int i = 2 * k; i >= 0; i--) {
    for (int j = 2 * k; j >= 0; j--) {
     if (i >= h[a]) dp[i][j] = min (dp[i][j], dp[i - h[a]][j] + 1);
     if (j >= h[a]) dp[i][j] = min (dp[i][j], dp[i][j - h[a]] + 1);
    }
   }
  }
  for (int i = 0; i <= 2 * k; i++) {
   debug (i, dp[i]);
  }
  int64_t ans = INT_MAX;
  for (int i = k; i <= 2 * k; i++) {
   for (int j = k; j <= 2 * k; j++) {
    ans = min (ans, dp[i][j]);
   }
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << '\n';
 }
 return 0;
}
