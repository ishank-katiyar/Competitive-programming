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
 vector<int> A (7);
 for (int i = 1; i <= 6; i++) cin >> A[i];
 int n;
 cin >> n;
 int N = n;
 vector<int> b (n);
 for (auto& i: b) cin >> i;
 vector<pair<int, int>> a;
 for (int i = 0; i < n; i++) {
  for (int j = 1; j <= 6; j++) {
   a.emplace_back (b[i] - A[j], i);
  }
 }
 sort (a.begin(), a.end());
 debug (a);
 int ans = INT_MAX;
 set<int> s;
 multiset<int> ms;
 int j = -1;
 n = (int) a.size();
 for (int i = 0; i < n; i++) {
  debug (i, a[i]);
  if (i > 0) {
   ms.erase (ms.find (a[i - 1].second));
   if (ms.count (a[i - 1].second) == 0) s.erase (a[i - 1].second);
  }
  while (j < n && (int) s.size() < N) {
   j++;
   s.insert (a[j].second);
   ms.insert (a[j].second);
  }
  debug (i, j);
  if ((int) s.size() == N && j < n) ans = min (ans, a[j].first - a[i].first);
 }
 cout << ans << '\n';
 return 0;
}