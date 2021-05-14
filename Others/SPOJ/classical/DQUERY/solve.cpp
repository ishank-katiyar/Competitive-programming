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

const int maxa = 1e6 + 1;
vector<int> c (maxa, 0);
const int S = 100;

void ADD (int a, int& ans) {
 assert (a < maxa);
 if (c[a] == 0) ans++;
 c[a]++;
}

void REMOVE (int a, int& ans) {
 assert (a < maxa);
 if (c[a] == 1) ans--;
 c[a]--;
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 vector<int> a (n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 int q;
 cin >> q;
 vector<pair<pair<int, int>, int>> Q (q);
 vector<int> ans (q, -1);
 for (int i = 0; i < q; i++) {
  int l, r;
  cin >> l >> r;
  Q[i].first.first = --l;
  Q[i].first.second = --r;
  Q[i].second = i;
 }
 sort (Q.begin(), Q.end(), [] (const pair<pair<int, int>, int> A, const pair<pair<int, int>, int> B) -> bool {
  if ((A.first.first / S) != (B.first.first / S)) {
   return (A.first.first / S) < (B.first.first / S);
  }
  return A.first.second < B.first.second;
 });
 debug (Q);
 int L = 0, R = -1;
 int ANS = 0;
 for (int i = 0; i < q; i++) {
  int l = Q[i].first.first;
  int r = Q[i].first.second;
  while (L > l) {
   L--;
   ADD(a[L], ANS);
  }
  while (L < l) {
   REMOVE (a[L], ANS);
   L++;
  }
  while (R < r) {
   R++;
   ADD (a[R], ANS);
  }
  while (R > r) {
   REMOVE (a[R], ANS);
   R--;
  }
  ans[Q[i].second] = ANS;
 }
 for (int i = 0; i < q; i++) {
  assert (ans[i] != -1);
  cout << ans[i] << '\n';
 }
 return 0;
}
