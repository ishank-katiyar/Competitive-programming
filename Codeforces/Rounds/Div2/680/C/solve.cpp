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
  long long p, q;
  cin >> p >> q;
  if (p % q != 0) {
   cout << p << '\n';
   continue;
  }
  long long ans = 1;
  for (long long i = 1; i * i <= q; i++) {
   if (q % i) continue;
   long long f = i;
   long long s = q / i;
   assert (p % f == 0);
   assert (p % s == 0);
   long long F = p;
   long long S = p;
   while (F % f == 0 && f != 1) {
    F /= f;
    if (p % F == 0 && F % q != 0) ans = max (ans, F);
   }
   while (S % s == 0 && s != 1) {
    S /= s;
    if (p % S == 0 && S % q != 0) ans = max (ans, S);
   }
  }
  assert (p % ans == 0 && ans % q != 0);
  cout << ans << '\n';
 }
 return 0;
}
