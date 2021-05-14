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
 vector<long long> pre (1, 2);
 for (int i = 2; i < 63; i++) {
  long long x = 2 * pre.back();
  x += 2;
  debug (i, x);
  pre.push_back (x);
 }
 int t;
 cin >> t;
 while (t--) {
  long long K;
  cin >> K;
  if (K % 2 == 1) {
   cout << -1 << '\n';
   continue;
  }
  vector<int> ans;
  while (K > 2) {
   auto it = upper_bound (pre.begin(), pre.end(), K);
   assert (it != pre.begin());
   it--;
   assert (*it <= K);
   int cnt = it - pre.begin();
   ans.push_back (1);
   while (cnt--) ans.push_back (0);
   K -= *it;
  }
  if (K == 2) {
   ans.push_back (1);
   K -= 2;
  }
  cout << int (ans.size()) << '\n';
  for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
