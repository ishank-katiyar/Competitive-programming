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
  string s;
  cin >> s;
  vector<vector<int>> idx(10);
  for (int i = 0; i < n; i++) idx[s[i] - '0'].push_back(i);
  int x = -1;
  int prev = -1;
  for (int i = 0; i < 10; i++) {
   if (idx[i].empty() == true) continue;
   if (prev == -1 && idx[i].empty() == false) {
    prev = i;
    continue;
   }
   if (*idx[i].begin() < *(--idx[prev].end())) {
    x = i; 
    prev = i;
    break;
   }
   else prev = i;
  }
  if (x == -1) x = prev;
  vector<int> ans(n);
  for (int i = 0; i < x; i++) {
   for (auto& j: idx[i]) ans[j] = 1;
  }
  if (x <= 8) {
   int nxt = -1;
   for (int i = x + 1; i < 10; i++) {
    if (idx[i].empty() == false) {
     nxt = i;
     break;
    }
   }
   if (nxt != -1) {
    int xx = *idx[nxt].begin();
    for (auto& i: idx[x]) if (i < xx) ans[i] = 2;
    for (auto& i: idx[x]) if (ans[i] == 0) ans[i] = 1;
   }
  }
  for (auto& i: ans) if (i == 0) i = 2;
  debug(ans);
  string ss;
  for (int i = 0; i < n; i++) {
   if (ans[i] == 1) ss += s[i];
  }
  for (int i = 0; i < n; i++) {
   if (ans[i] == 2) ss += s[i];
  }
  debug(ss);
  assert ((int) ss.size() == n);
  bool ok = true;
  for (int i = 1; i < n; i++) if (ss[i] < ss[i - 1]) ok = false;
  if (ok == false) cout << '-';
  else for (auto& i: ans) cout << i;
  cout << '\n';
 }
 return 0;
}
