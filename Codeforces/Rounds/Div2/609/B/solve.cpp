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
 int m;
 cin >> m;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 vector<int> b(n);
 for (auto& i: b) cin >> i;

 auto diff = [&] (vector<int> &A) -> vector<int> {
  int N = (int) A.size();
  vector<int> ret(N - 1);
  for (int i = 1; i < N; i++) {
   ret[i - 1] = A[i] - A[i - 1];
  }
  return ret;
 };

 sort(a.begin(), a.end());
 sort(b.begin(), b.end());

 if (a == b) {
  cout << 0 << '\n';
  return 0;
 }

 int ans = m - a[n - 1] - 1;
 for (auto& i: a) i += ans;

 while (1) {
  if (diff(a) == diff(b)) {
   int X = b[0] - a[0];
   if (X >= 0) {
    ans += X;
    break;
   }
  }
  int x = m - a[n - 1];
  ans += x;
  for (auto& i: a) i += x, i %= m;
  sort(a.begin(), a.end());
 }
 cout << ans << '\n';
 return 0;
}
