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
  int n;
  cin >> n;
  vector<pair<long long, long long>> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first;
  } 
  for (int i = 0; i < n; i++) {
   cin >> a[i].second;
  } 
  sort (a.begin(), a.end(), [&] (const pair<long long, long long> A, const pair<long long, long long> B) {
   if (A.first == B.first) return A.second < B.second;
   return A.first > B.first;
  });
  debug (a);
  long long ans = a[0].first;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
   sum += a[i].second;
   if (i == n - 1) {
    ans = min (ans, sum);
   }
   else {
    ans = min (ans, max (sum, a[i + 1].first));
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
