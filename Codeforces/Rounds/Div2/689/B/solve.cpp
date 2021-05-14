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
  vector<string> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }

  vector<vector<int>> dp (n, vector<int> (m));
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    if (j == 0) {
     if (a[i][j] == '*') dp[i][j] = 1;
    }
    else {
     if (a[i][j] == '*') dp[i][j] += dp[i][j - 1] + 1;
     else dp[i][j] = dp[i][j - 1];
    }
   }
  }

  debug (dp);

  auto check = [&] (int k, int x, int y) -> bool {
   if  (x < 0) {
    return false;
   }
   if (x >= m || y >= m || k >= n) {
    return false;
   }
   if (x == 0) {
    if (dp[k][y] == y + 1) return true;
    return false;
   }
   if (dp[k][y] - dp[k][x - 1] == y - x + 1) return true;
   return false;
  };

  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
   for (int j = 0; j < m; j++) {
    if (a[i][j] == '*') {
     long long level = 0;
     for (int k = i; k < n; k++) {
      if (check (k, j - level, j + level)) level++;
      else break;
     }
     debug (i, j, level);
     ans += level;
     // auto aa = [] (long long X) -> long long {
     //  return X * X;
     // };
     // for (long long x = 1; x <= level; x++) {
     //  ans += aa (x);
     // }
    }
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
