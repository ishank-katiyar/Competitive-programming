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
 vector<double> a(n);
 int diff = 0;
 int pos = 0, neg = 0;
 vector<int> ans(n);
 int c = 0;
 for (auto& i: a) {
  cin >> i;
  diff += (int) i;
  int x = (int) i;
  ans[c++] = x;
  if ((double) x == i) continue;
  if (i > 0) pos++;
  else if (i < 0) neg++;
 }
 debug(pos, neg);
 if (diff > 0) assert (diff <= neg);
 if (diff < 0) assert (diff <= pos);
 for (int i = 0; i < n; i++) {
  int x = (int) a[i];
  if ((double) x == a[i]) continue;
  debug(x, a[i]);
  if (diff > 0) {
   if (a[i] < 0) {
    ans[i] = x - 1;
    diff--;
   }
  }
  if (diff < 0 && a[i] > 0) {
   ans[i] = x + 1;
   diff++;
  }
 }
 assert (accumulate(ans.begin(), ans.end(), 0LL) == 0LL);
 for (auto& i: ans) cout << i << '\n';
 return 0;
}
