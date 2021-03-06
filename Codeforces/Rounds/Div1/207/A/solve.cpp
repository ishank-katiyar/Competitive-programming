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
 int n, m;
 cin >> n >> m;
 vector<int> ans(n + 1);
 set<int> s;
 for (int i = 1; i <= n; i++) s.insert(i);
 while (m--) {
  int l, r, winner;
  cin >> l >> r >> winner;
  auto it = s.lower_bound(l);
  vector<int> del;
  while (*it <= r && it != s.end()) {
   debug(l, r, s, *it);
   if (*it != winner) {
    ans[*it] = winner;
    del.push_back(*it);
   }
   it++;
  }
  for (auto& i: del) s.erase(i);
 }
 for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
 cout << '\n';
 return 0;
}
