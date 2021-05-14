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
  int x;
  cin >> x;
  int n = (int) s.size();
  string w = string(n, '1');
  for(int i = 0; i < n; i++) {
   if(s[i] == '0') {
    int j = i - x;
    if(j >= 0) w[j] = '0';
    j = i + x;
    if(j < n) w[j] = '0';
   }
  }
  debug(w);
  string ss = string(n, '1');
  for(int i = 0; i < n; i++) {
   bool ok = true;
   if(i - x >= 0 && w[i - x] == '1') ok = false;
   if(i + x < n && w[i + x] == '1') ok = false;
   if(ok) ss[i] = '0';
  }
  debug(ss);
  cout << (ss == s ? w : "-1") << '\n';
 }
 return 0;
}
