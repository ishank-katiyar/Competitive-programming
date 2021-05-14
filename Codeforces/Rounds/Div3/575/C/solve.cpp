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
  const int maxn = 1e5;
  int mnx = -maxn, mxx = maxn;
  int mny = -maxn, mxy = maxn;
  while (n--) {
   int x, y, f1, f2, f3, f4;
   cin >> x >> y >> f1 >> f2 >> f3 >> f4;
   if (f1 == 0) mnx = max(mnx, x);
   if (f2 == 0) mxy = min(mxy, y);
   if (f3 == 0) mxx = min(mxx, x);
   if (f4 == 0) mny = max(mny, y);
  }
  if (mnx <= mxx && mny <= mxy) cout << "1 " << mnx << " " << mny << "\n";
  else cout << "0\n";
 }
 return 0;
}
