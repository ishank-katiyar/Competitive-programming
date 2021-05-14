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
 int n;
 cin >> n;
 vector<pair<int, int>> a, b;
 vector<pair<int, int>> zero;
 for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
  if (x > 0) a.push_back(make_pair(x, i));
  if (x == 0) zero.push_back(make_pair(x, i));
  if (x < 0) b.push_back(make_pair(x, i));
 }
 debug(a, b, zero);
 int sz = (int) a.size();
 while (sz--) {
  b.push_back({-1 * (a.back().first + 1), a.back().second});
  a.pop_back();
 }
 sz = (int) zero.size();
 while (sz--) {
  b.push_back({-1 * (zero.back().first + 1), zero.back().second});
  zero.pop_back();
 }
 sort(b.begin(), b.end());
 debug(a, b, zero);
 sz = (int) b.size();
 if (sz % 2 == 1 && b[0].first == -1) {
  zero.emplace_back(0, b[0].second);
  b.erase(b.begin());
  sz--;
 }
 if (sz % 2 == 1) {
  auto it = b.begin();
  int x = it->first;
  assert (x < -1);
  int idx = it->second;
  b.erase(it);
  x++;
  x = -x;
  a.emplace_back(x, idx);
 }
 debug(a, b, zero);
 vector<int> ans(n, 1e9);
 for (auto& i: a) {
  assert (ans[i.second] == 1e9);
  ans[i.second] = i.first;
 }
 for (auto& i: zero) {
  assert (ans[i.second] == 1e9);
  ans[i.second] = i.first;
 }
 for (auto& i: b) {
  assert (ans[i.second] == 1e9);
  ans[i.second] = i.first;
 }
 for (int i = 0; i < n; i++) {
  assert (ans[i] != 1e9);
  cout << ans[i] << ' ';
 }
 cout << '\n';
 return 0;
}
