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
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>> (10, vector<int> (10, 0)));
  vector<int> prev_pos(10, -1);
  for(int i = 0; i < n; i++) {
   int x = s[i] - '0';
   for(int j = 0; j <= 9; j++) {
    if(prev_pos[j] == -1) dp[i][j][x] = 1;
    else {
     dp[i][j][x] += dp[prev_pos[j]][x][j] + 1;
    }
   }
   prev_pos[x] = i;
  }
  for(int i = 0; i < n; i++) {
   debug(i); 
   debug(dp[i]);
  }
  int ans = 1e9;
  for(int k = 0; k < n; k++) {
   for(int i = 0; i <= 9; i++) {
    for(int j = 0; j <= 9; j++) {
     ans = min(ans, n - dp[k][i][j] + (i != j ? (dp[k][i][j] % 2) : 0));
    }
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
