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
  string s;
  cin >> s;
  vector<int> a (26, 0);
  for (auto& i: s) a[i - 'a']++;
  sort (a.rbegin(), a.rend());
  int ans = 0;
  for (int i = 0; i < 26; i++) {
   int x = a[i] / 2;
   for (int j = 0; j < 26; j++) {
    if (i == j) continue;
    if (a[j] % 2 == 1 && x > 0)  a[j]--, x--;
   }
   for (int j = 25; j >= 0; j--) {
    if (i == j) continue;
    int mn = min (a[j], x);
    a[j] -= mn;
    x -= mn;
   }
   ans += (a[i] / 2 - x);
   a[i] -= 2 * (a[i] / 2 - x);
  }
  debug (a);
  for (int i = 0; i < 26; i++) ans += a[i] / 3;
  cout << ans << '\n';
 }
 return 0;
}
