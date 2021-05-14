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
  long long int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  while (s.empty() == false && s.back() == '0') s.pop_back();
  reverse (s.begin(), s.end());
  while (s.empty() == false && s.back() == '0') s.pop_back();
  reverse (s.begin(), s.end());
  if (s.empty() == true) {
   cout << 0 << '\n';
   continue;
  }
  debug (s);
  vector<long long> A;
  int cur = 0;
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
   if (s[i] == '1') {
    if (cur > 0) A.push_back (cur);
    cur = 0;
   }
   else cur++;
  } 
  assert (cur == 0);
  debug (A);
  n = (int) A.size();
  long long tt = n + 1;
  long long ans = tt * a;
  debug (ans);
  sort (A.begin(), A.end());
  long long sum = 0;
  for (int i = 0; i < n; i++) {
   sum += A[i];
   tt--;
   long long c = sum * b + tt * a;
   debug (i, c);
   ans = min (ans, c);
  }
  assert (tt == 1);
  // reverse (A.begin(), A.end());
  // sum = 0;
  // for (int i = 0; i < n; i++) {
  //  sum += A[i];
  //  long long c = sum * b;
  //  long long cnt = (n - i);
  //  c += cnt * a;
  //  debug (i, c);
  //  ans = min (ans, c);
  // }
  cout << ans << '\n';
 }
 return 0;
}
