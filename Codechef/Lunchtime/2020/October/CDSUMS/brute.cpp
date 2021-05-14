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
 int l, r;
 cin >> l >> r;
 int n = r - l + 1;
 vector<int> a (r - l + 1);
 for (int i = l; i <= r; i++) a[i - l] = i;
 set <int> s;
 for (int mask = 1; mask < (1LL << n); mask++) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
   if ((mask >> i) & 1) {
    sum += a[i];
   }
  }
  s.insert (sum);
 }
 // int sz = (n * (n + 1)) / 2;
 // assert ((int) s.size() == sz);
 cout << (int) s.size() << '\n';
 debug (s);
 return 0;
}
