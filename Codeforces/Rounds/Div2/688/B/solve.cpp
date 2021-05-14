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
  int n;
  cin >> n;
  vector<long long> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  debug (a);
  long long ans = 0;
  for (int i = 1; i < n; i++) {
   ans += abs (a[i] - a[i - 1]);
  }
  long long A = ans;
  debug ("sum", ans);
  for (int i = 1; i < n - 1; i++) {
   long long cur_ans = A;
   cur_ans -= abs (a[i] - a[i - 1]);
   cur_ans -= abs (a[i + 1] - a[i]);
   cur_ans += abs (a[i + 1] - a[i - 1]);
   ans = min (ans, cur_ans);
   debug (i, cur_ans);
  }
  ans = min ({ans, A - abs (a[1] - a[0]), A - abs (a.back() - a[n - 2])});
  cout << ans << '\n';
 }
 return 0;
}
