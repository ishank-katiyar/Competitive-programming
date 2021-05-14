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
 cout.tie(0);
 int n;
 cin >> n;
 string s;
 cin >> s;

 auto sum = [&] (string a, string b) -> string {
  debug(a, b);
  string ans = "";
  int carry = 0;
  reverse (a.begin(), a.end());
  reverse (b.begin(), b.end());
  int sz = max((int) a.size(), (int) b.size());
  while ((int) a.size() < sz) a += "0";
  while ((int) b.size() < sz) b += "0";
  for (int i = 0; i < sz; i++) {
   int Sum = int(a[i] - '0') + int(b[i] - '0') + carry;
   ans += char((Sum % 10) + '0');
   carry = Sum / 10;
  }
  debug(carry);
  while (carry > 0) ans += char((carry % 10) + '0'), carry /= 10;
  reverse (ans.begin(), ans.end());
  debug(ans);
  return ans;
 };
 
 auto ret_min = [&] (string a, string b) -> string {
  debug(a, b);
  reverse (a.begin(), a.end());
  reverse (b.begin(), b.end());
  int sz = max((int) a.size(), (int) b.size());
  while ((int) a.size() < sz) a += "0";
  while ((int) b.size() < sz) b += "0";
  reverse (a.begin(), a.end());
  reverse (b.begin(), b.end());
  bool first = true;
  for (int i = 0; i < sz; i++) {
   if (a[i] == b[i]) continue;
   first = (a[i] > b[i]);
   break;
  }
  first ^= 1;
  string mn = first ? a : b;
  debug(mn);
  return mn;
 };

 auto ret = [&] (string a, int idx) -> pair<int, int> {
  pair<int, int> ans = make_pair(-1, -1);
  while (idx >= 0) {
   if (a[idx] == '0') {
    idx--;
    continue;
   }
   ans.first = idx; 
   break;
  } 
  assert (ans.first != -1);
  idx++;
  while (idx < (int) a.size()) {
   if (a[idx] == '0') {
    idx++;
    continue;
   } 
   ans.second = idx;
   break;
  }
  if (ans.second == -1) ans.second = ans.first;
  return ans;
 };

 string ans = "";
 if (n % 2 == 0) {
  if (s[n / 2] == '0') {
   pair<int, int> aa = ret(s, n / 2);
   ans = ret_min (sum(s.substr(0, aa.first), s.substr(aa.first)), sum(s.substr(0, aa.second), s.substr(aa.second)));
  } 
  else ans = sum(s.substr(0, n / 2), s.substr(n / 2));
 }
 else {
  if (s[n / 2] == '0') {
   pair<int, int> aa = ret(s, n / 2);
   ans = ret_min (sum(s.substr(0, aa.first), s.substr(aa.first)), sum(s.substr(0, aa.second), s.substr(aa.second)));
  } 
  else ans = sum(s.substr(0, n / 2), s.substr(n / 2));
  n++;
  if (s[n / 2] == '0') {
   pair<int, int> aa = ret(s, n / 2);
   string ans1 = ret_min (sum(s.substr(0, aa.first), s.substr(aa.first)), sum(s.substr(0, aa.second), s.substr(aa.second)));
   ans = ret_min (ans1, ans);
  } 
  else ans = ret_min(ans, sum(s.substr(0, n / 2), s.substr(n / 2)));
 }
 reverse(ans.begin(), ans.end());
 while (ans.empty() == false && ans.back() == '0') ans.pop_back();
 if (ans.empty() == true) ans = "0";
 reverse(ans.begin(), ans.end());
 cout << ans << '\n';
 return 0;
}
