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
 long double r;
 cin >> r;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 for (int i = 0; i < n; i++) {
  debug(i + 1, a[i]);
 }
 vector<long double> ans(n, 0.0);
 for (int i = 0; i < n; i++) {
  for (int j = i - 1; j >= 0; j--) {
   if (abs(a[i] - a[j]) <= 2 * r) {
    long double h = sqrt(pow(2 * r, 2) - pow(abs(a[i] - a[j]), 2));
    ans[i] = max(ans[i], h + ans[j]);
   }
  }
  if (ans[i] == 0.0) ans[i] = r;
 }
 for (int i = 0; i < n; i++) {
  //cout << i + 1 << ' ';
  cout << fixed << setprecision(10) << ans[i] << ' ';
 }
 cout << '\n';
 return 0;
}
