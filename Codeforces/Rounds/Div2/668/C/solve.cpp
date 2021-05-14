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

class DSU {
public:
 int n;
 vector<int> Parent;
 vector<int> Size;
 DSU (int N) {
  n = N;
  Parent.assign(n+1, 0);
  Size.assign(n+1, 0);
 }
 void make_set() {
  for(int i = 0; i <= n; i++) Parent[i] = i, Size[i] = 1;
 }
 int rep(int N) {
  if(Parent[N] == N) return N;
  return Parent[N] = rep(Parent[N]);
 }
 void Union(int A, int B) {
  int RA = rep(A);
  int RB = rep(B);
  if(RA != RB) {
   if(Size[RA] < Size[RB]) {
    swap(RA, RB);
   }
   Parent[RB] = RA;
   Size[RA] += Size[RB];
  }
 }
};

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  DSU a(n);
  a.make_set();
  for(int i = k; i < n; i++) {
   a.Union(i - k, i);
  }
  map<int, vector<int>> mp;
  for(int i = 0; i < n; i++) {
   mp[a.rep(i)].push_back(i);
  }
  auto f = [&] (vector<int> &aa) -> bool {
   map<char, int> mm;
   for(auto& i: aa) mm[s[i]]++;
   if(mm['1'] > 0 && mm['0'] > 0) return false;
   char ch = '#';
   if(mm['1'] > 0) ch = '1';
   else if(mm['0'] > 0) ch = '0';
   if(ch == '#') return true;
   for(auto& i: aa) if(s[i] == '?') s[i] = ch;
   return true;
  };
  bool ok = true;
  for(auto& i: mp) ok &= f(i.second);
  debug(s);
  int c1 = 0;
  int c2 = 0;
  for(int i = 0; i < k; i++) {
   if(s[i] == '1') c2++;
   else if(s[i] == '0') c1++;
  }
  bool ok2 = false;
  int ee = k - c1 - c2;
  debug(c1, c2, ee);
  if(ee >= abs(c1 - c2) && (ee - abs(c1 - c2)) % 2 == 0) ok2 = true;
  cout << (ok && ok2 ? "YES" : "NO") << '\n';
 }
 return 0;
} 
