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
 int n;
 cin >> n;
 string s;
 cin >> s;
 debug (n, s);
 long long ans = pow (10, 10);
 if (n == 1) {
  ans *= (s[0] == '0' ? 1 : 2);
  cout << ans << '\n';
  return 0;
 }
 string S = "110";
 string ss = "";
 while (int(ss.size()) <= n) ss += S;
 ss += ss;
 debug (ss);
 long long tt = (int) ss.size() / 3;
 long long cnt = 0;
 for (int i = 0; i <= tt * 3 - n; i++) {
  debug (ss.substr (i, n), s);
  if (ss.substr (i, n) == s) cnt++;
 }
 long long Ans = cnt + (ans - tt);
 if (cnt == 0) Ans = 0;
 cout << Ans << '\n';
 return 0;
}
