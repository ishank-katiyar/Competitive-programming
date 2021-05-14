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
  int n, p, k;
  cin >> n >> p >> k;
  p--;
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  vector<int> em (n);
  for (int idx = p; idx < p + k; idx++) {
   int ei = idx;
   while (ei < n) {
    ei += k;
   }
   ei -= k;
   int sum = 0;
   while (ei >= idx) {
    if (s[ei] == '0') {
     sum++;
    }
    em[ei] = sum;
    ei -= k;
   }
  }
  debug (em);
  int ans = INT_MAX;
  for (int i = p; i < n; i++) {
   int cur_ans = (i - p) * y;
   cur_ans += em[i] * x;
   ans = min (ans, cur_ans);
  }
  cout << ans << '\n';
 }
 return 0;
}
