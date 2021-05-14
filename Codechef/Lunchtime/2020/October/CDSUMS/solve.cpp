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
  long long int l, r;
  cin >> l >> r;
  if (l == 1) {
   cout << (r * (r + 1)) / 2 << '\n';
   continue;
  }
  // {{{
  // else if (l <= (int) 1e4 && r <= (int) 1e4) {
  //  long long ans = 0;
  //  int n = r - l + 1;
  //  vector<long long> pre (n), suf (n);
  //  for (int i = 1; i < n; i++) {
  //   pre[i] += pre[i - 1] + i;
  //  }
  //  suf[n - 1] = n - 1;
  //  for (int i = n - 2; i >= 0; i--) {
  //   suf[i] += suf[i + 1] + i;
  //  }
  //  reverse (suf.begin(), suf.end());
  //  debug (pre, suf);
  //  for (int C = 1; C <= r - l + 1; C++) {
  //   ans += (suf[C - 1] - pre[C - 1]) + 1;
  //  }
  //  cout << ans << '\n';
  // }
  // else cout << 0 << '\n';
  // }}}
  long long ans = 0;
  int n = r - l + 1;
  vector<long long> pre (n), suf (n);
  for (int i = 1; i < n; i++) {
   pre[i] += pre[i - 1] + i;
  }
  suf[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
   suf[i] += suf[i + 1] + i;
  }
  reverse (suf.begin(), suf.end());
  debug (pre, suf);
  vector<pair<long long int, long long int>> a;
  a.emplace_back (l, r);
  for (int i = 1; i < n; i++) {
   long long first = (i + 1) * l + pre[i];
   long long last = (i + 1) * l + suf[i];
   debug (first, last);
   if (a.back().second >= first) {
    first = a.back().first;
    a.pop_back();
   }
   a.emplace_back (first, last);
   // ans += (suf[i] - pre[i]) + 1;
  }
  debug (a);
  for (auto& i: a) {
   ans += (i.second - i.first + 1);
  }
  cout << ans << '\n';
 }
 return 0;
}
