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
  int n, m, k;
  cin >> n >> m >> k;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
   int cnt = min (i, n);
   if (cnt % 2 == 1) {
    ans ^= (k + i + 1);
    debug (k + i + 1);
   }
  }
  for (int i = 2; i <= n; i++) {
   int cnt = min (n - i + 1, m);
   if (cnt % 2 == 1) {
    ans ^= (k + i + m);
    debug (k + i + m);
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
