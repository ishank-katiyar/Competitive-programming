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
  int64_t n, m, k;
  cin >> n >> m >> k;
  vector<vector<int64_t>> a (n + 1, vector<int64_t> (m + 1));
  vector<vector<int64_t>> dp (n + 1, vector<int64_t> (m + 1));
  for (int i = 1; i <= n; i++) {
   int64_t sum = 0;
   for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
    sum += a[i][j];
    dp[i][j] = sum + dp[i - 1][j];
   }
  }

  debug (dp);

  auto check = [&]  (int x, int y) -> bool {
   // assert (x >= 1 && x <= n);
   // assert (y >= 1 && y <= m);
   return (x >= 1 && x <= n) && (y >= 1 && y <= m);
  };

  auto f = [&] (int x, int y, int x1, int y1) -> int64_t {
   assert (check (x, y));
   assert (check (x1, y1));
   return dp[x1][y1] - dp[x - 1][y1] - dp[x1][y - 1] + dp[x - 1][y - 1];
  };

  int64_t ans = 0;

  auto ff = [&] (int x, int y) {
   pair <int, int> p1, p2;
   p1 = make_pair (x, y);
   p2 = p1;
   while (check (p2.first, p2.second) == true && check (p1.first, p1.second) == true) {
    while (check (p2.first, p2.second) && f (p1.first, p1.second, p2.first, p2.second) < k * (p2.first - p1.first + 1) * (p2.first - p1.first + 1)) {
     p2.first += 1;
     p2.second += 1;
    }
    if (check (p2.first, p2.second)) {
     debug (p1, p2, f (p1.first, p1.second, p2.first, p2.second));
     ans += min (n - p2.first + 1, m - p2.second + 1);
    }
    p1.first += 1;
    p1.second += 1;
   }
  };

  for (int i = n; i >= 2; i--) {
   ff (i, 1);
  }
  for (int i = 1; i <= m; i++) {
   ff (1, i);
  }
  cout << ans << '\n';
 }
 return 0;
}
