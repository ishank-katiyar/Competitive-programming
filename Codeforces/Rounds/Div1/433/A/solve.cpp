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
 int n, k;
 cin >> n >> k;
 set<long long int> s;
 for (int i = k + 1; i <= k + n; i++) {
  s.insert(i); 
 }
 vector<pair<long long int, long long int>> a(n);
 for (int i = 1; i <= n; i++) {
  cin >> a[i - 1].first;
  a[i - 1].second = i;
 }
 sort (a.rbegin(), a.rend());
 long long int ANS = 0;
 vector<int> ans (n + 1);
 for (int i = 0; i < n; i++) {
  auto it = s.lower_bound(a[i].second);
  assert(it != s.end());
  ans[a[i].second] = *it;
  ANS += a[i].first * (*it - a[i].second);
  s.erase(it);
  debug(*it, s);
 }
 cout << ANS << '\n';
 for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
 cout << '\n';
 return 0;
}
