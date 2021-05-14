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
 vector<int> a(3);
 for (auto& i: a) cin >> i;
 vector<int> b(3);
 for (auto& i: b) cin >> i;
 int mx = min(a[0], b[1]) + min (a[1], b[2]) + min (a[2], b[0]);
 int mn;
 auto get = [&] (int i) -> int  {
  vector<int> aa(b);
  vector<int> bb(a);
  int j = (i + 1) % 3;
  int mm1 = min(aa[i], bb[j]);
  aa[i] -= mm1;
  bb[j] -= mm1;
  int mm2 = min(aa[i], bb[i]);
  aa[i] -= mm2;
  bb[i] -= mm2;
  i++;
  i %= 3;
  j = (i + 1) % 3;
  mm1 = min(aa[i], bb[j]);
  aa[i] -= mm1;
  bb[j] -= mm1;
  mm2 = min(aa[i], bb[i]);
  aa[i] -= mm2;
  bb[i] -= mm2;
  i++;
  i %= 3;
  j = (i + 1) % 3;
  mm1 = min(aa[i], bb[j]);
  aa[i] -= mm1;
  bb[j] -= mm1;
  mm2 = min(aa[i], bb[i]);
  aa[i] -= mm2;
  bb[i] -= mm2;
  debug(aa, bb);
  return *max_element(aa.begin(), aa.end());
 };
 mn = min(get(0), min(get(1), get(2)));
 cout << mn << ' ' << mx << '\n';
 return 0;
}
