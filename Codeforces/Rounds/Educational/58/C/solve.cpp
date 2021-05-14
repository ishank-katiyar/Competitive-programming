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
  vector<pair<int, int>> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
   int x, y;
   cin >> x >> y;
   a[i] = make_pair(x, y);
   mp[x]++, mp[y]--;
  }
  int p = -1;
  int sum = 0;
  for (auto& i: mp) {
   sum += i.second;
   if (sum == 0) {
    p = i.first;
    break;
   }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
   if (a[i].second <= p) ans[i] = 1;
   else ans[i] = 2;
  }
  if (count(ans.begin(), ans.end(), 1) == n || count(ans.begin(), ans.end(), 2) == n) cout << -1;
  else for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
