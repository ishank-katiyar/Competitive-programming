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
  vector<long long> a (n);
  for (auto& i: a) cin >> i;
  const int maxbit = 60;
  vector<int> c (maxbit, 0);
  for (auto& i: a) {
   for (int j = 0; j < maxbit; j++) {
    if ((i >> j) & 1) {
     c[j]++;
    }
   }
  }
  debug (c);
  long long ans = 0;
  for (int i = 1; i < maxbit; i++) {
   c[i] += c[i - 1] / 2;
  }
  for (int i = 0; i < maxbit; i++) {
   // if (c[i] == 0) {
   //  bool ok = false;
   //  long long int k = 2;
   //  int C = i - 1;
   //  while (C >= 0) {
   //   if (c[C] >= k) {
   //    ok = true;
   //    break;
   //   }
   //   k *= 2;
   //   C--;
   //  }
   //  debug (i, ok);
   //  if (ok == true) ans += (1LL << i);
   // }
   // else {
   //  ans += (1LL << i);
   // }
   if (c[i] > 0) ans += (1LL << i);
  }
  cout << ans << '\n';
 }
 return 0;
}
