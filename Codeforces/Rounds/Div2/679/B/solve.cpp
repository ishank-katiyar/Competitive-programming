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
  vector<vector<int>> a (n, vector<int> (m));
  for (auto& i: a) for (auto& j: i) cin >> j;
  vector<int> c (n * m + 1, 0);
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    c[a[i][j]] = i;
   }
  }
  debug (c);
  vector<vector<int>> b (m, vector<int> (n));
  for (auto& i: b) for (auto& j: i) cin >> j;
  vector<int> order;
  for (auto& i: b[0]) {
   order.push_back (c[i]);
  }
  debug (order);
  assert ((int) order.size() == n);
  for (auto& i: order) {
   for (auto& j: a[i]) {
    cout << j << ' ';
   }
   cout << '\n';
  }
 }
 return 0;
}
