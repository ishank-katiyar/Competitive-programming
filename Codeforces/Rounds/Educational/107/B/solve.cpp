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
 const int maxn = 12;
 vector<int64_t> a2 (maxn), a3 (maxn);
 a2[0] = a3[0] = 1;
 auto f = [] (int64_t X) -> int {
  int ans = 0;
  while (X) {
   ans += 1;
   X /= 10;
  }
  return ans;
 };
 int64_t x = 1;
 while (f (x) < maxn) {
  x *= 2;
  a2[f (x)] = x;
 }
 x = 1;
 while (f (x) < maxn) {
  x *= 3;
  a3[f (x)] = x;
 }
 debug (a2);
 debug (a3);
 int t;
 cin >> t;
 while (t--) {
  int a, b, c;
  cin >> a >> b >> c;
  c -= 1;
  a -= c;
  b -= c;
  int x1 = a2[a] * pow (10, c);
  int x2 = a3[b] * pow (10, c);
  cout << x1 << ' ' << x2 << '\n';
 }
 return 0;
}
