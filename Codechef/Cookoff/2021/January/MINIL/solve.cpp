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
 int maxn = 100, maxm = 100;
 vector<string> A (maxn);
 string S = "";
 for (int i = 0; i < maxm; i++) {
  S += (i % 2 ? "*" : ".");
 }
 for (int i = 0; i < maxn; i++) {
  S += S[0];
  S.erase (S.begin());
  A[i] = S;
 }
 vector<string> B(A);
 B.push_back (B[0]);
 B.erase (B.begin());
 debug (A);
 debug (B);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  assert (n <= 10 && m <= 10);
  int mx1 = 0, mx2 = 0;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    if (A[i][j] == '*') mx1++;
    if (B[i][j] == '*') mx2++;
   }
  }
  vector<string> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }

  auto f = [] (const vector<string> &aa, const vector<string> &bb, const int &N, const int &M) -> int {
   int ret = 0;
   for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
     ret += (aa[i][j] != bb[i][j]);
    }
   }
   return ret;
  };

  if (mx1 == mx2) cout << min (f (a, A, n, m), f (a, B, n, m)) << '\n';
  else if (mx1 > mx2) cout << f (a, A, n, m) << '\n';
  else cout << f (a, B, n, m) << '\n';
 }
 return 0;
}
