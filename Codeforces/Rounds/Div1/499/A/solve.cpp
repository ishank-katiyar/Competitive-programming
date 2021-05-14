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
 vector<int> aa(1, a[0]);
 for (int i = 1; i < n; i++) {
  aa.push_back(b[i]);
  aa.push_back(a[i]);
 }
 aa.push_back(b[0]);
 debug(aa);
 reverse(aa.begin(), aa.end());
 long double ans = 0.0;
 long double cur_wei = m;
 n = (int) aa.size();
 bool ok = true;
 for (int i = 0; i < n; i++) {
  if (aa[i] == 1) {
   ok = false;
   break;
  }
  aa[i]--;
  long double add = cur_wei / (long double) aa[i];
  cur_wei += add;
 }
 ans = cur_wei - (long double) m;
 if (ok) cout << fixed << setprecision(10) << ans << '\n';
 else cout << -1 << '\n';
 return 0;
}
