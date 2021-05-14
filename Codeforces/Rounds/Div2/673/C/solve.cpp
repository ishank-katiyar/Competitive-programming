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
 while (t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i: a) cin >> i;
  vector<vector<int>> idx(n + 1);
  for (int i = 1; i <= n; i++) {
   idx[i].push_back(0);
  }
  for (int i = 1; i <= n; i++) idx[a[i - 1]].push_back(i);
  for (int i = 1; i <= n; i++) {
   idx[i].push_back(n + 1);
  }
  vector<int> mx(n + 1, n);
  for (int i = 1; i <= n; i++) {
   int ans = 0;
   int sz = (int) idx[i].size();
   for (int j = 1; j < sz; j++) {
    ans = max(ans, idx[i][j] - idx[i][j - 1]);
   }
   debug(i, ans);
   //if (ans == n + 1) continue;
   mx[i] = ans;
  }
  debug(mx);
  vector<int> ans(n + 2, -1);
  for (int i = n; i >= 1; i--) ans[mx[i]] = i;
  debug(ans);
  for (int i = 2; i <= n; i++) {
   if (ans[i] == -1) ans[i] = ans[i - 1]; 
   else if (ans[i - 1] != -1) ans[i] = min (ans[i], ans[i - 1]);
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << '\n';
 }
 return 0;
}
