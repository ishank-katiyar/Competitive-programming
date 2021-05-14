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
 int T;
 cin >> T;
 for (int tt = 1; tt <= T; tt++) {
  int n;
  cin >> n;
  vector<int> a (n);
  int ans = 0;
  auto f = [] (int aa, int b) -> bool {
   string A = to_string (aa);
   string B = to_string (b);
   while (int (B.size()) > int (A.size())) {
    B.pop_back ();
   }
   return A == B;
  };
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   int x = a[i];
   if (i > 0) {
    while (a[i] <= a[i - 1] || f (x, a[i]) == false) {
     a[i] += 1;
    }
   }
   ans += int (to_string (a[i]).size()) - int (to_string (x).size());
  }
  debug (a);
  cout << "Case #" << tt << ": " << ans << '\n';
 }
 return 0;
}
