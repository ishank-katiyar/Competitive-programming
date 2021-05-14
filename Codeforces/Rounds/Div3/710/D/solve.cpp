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
  vector<int> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  sort (a.begin(), a.end());
  map <int, pair<int, int>> mp;
  for  (int i = 0; i < n; i++) {
   if (mp.count (a[i]) == 0) {
    mp[a[i]].first = i;
    mp[a[i]].second = i;
   } else {
    mp[a[i]].second = i;
   }
  }
  int ans = n;
  for (int i = 0; i < n; i++) {
   int second = n - mp[a[i]].second - 1;
   int cnt = i - mp[a[i]].first + 1;
   debug (i, second, cnt);
   if (cnt > second) {
    ans = min (ans, n - 2 * second);
   } else {
    ans = min (ans, n - 2 * min (i + 1, n - i - 1));
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
