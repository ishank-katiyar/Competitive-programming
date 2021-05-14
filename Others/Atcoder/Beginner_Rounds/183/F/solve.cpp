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

struct node {
 int n;
 map <int, int> mp;
};

const int maxn = 4e5 + 1;
vector<node> info (maxn);

void merge (int ra, int rb) {
 map <int, int> m1 = info[ra].mp;
 map <int, int> m2 = info[rb].mp;
 // debug (m1, m2);
 for (auto& i: m2) {
  m1[i.first] += i.second;
 }
 info[ra].mp = m1;
 info[rb].mp.clear();
}

int get (int x, int y) {
 return info[x].mp[y];
}

class DSU {
public:
 int n;
 vector<int> Parent;
 vector<int> Size;
 DSU (int N) {
  n = N;
  Parent.assign(n + 1, 0);
  Size.assign(n + 1, 0);
  make_set();
 }
 
 void make_set() {
  for(int i = 0; i <= n; i++) {
   Parent[i] = i;
   Size[i] = 1;
  }
 }
 
 int rep(int N) {
  if(Parent[N] == N) return N;
  return Parent[N] = rep(Parent[N]);
 }
 
 void Union(int A, int B) {
  int RA = rep(A);
  int RB = rep(B);
  if(RA != RB) {
   int sz1 = info[RA].mp.size();
   int sz2 = info[RB].mp.size();
   if (sz1 < sz2) {
    swap(RA, RB);
   }
   debug (RA, RB);
   merge (RA, RB);
   Parent[RB] = RA;
   Size[RA] += Size[RB];
  }
 }
};

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, q;
 cin >> n >> q;
 vector<int> C (n + 1);
 for (int i = 1; i <= n; i++) {
  cin >> C[i];
  info[i].n = i;
  map <int, int> mm;
  mm[C[i]]++;
  info[i].mp = mm;
 }
 DSU dsu (n + 1);
 while (q--) {
  int type;
  cin >> type;
  if (type == 1) {
   int a, b;
   cin >> a >> b;
   dsu.Union (a, b);
  }
  else {
   int x, y;
   cin >> x >> y;
   int rr = dsu.rep (x);
   cout << get (rr, y) << '\n';
  }
 }
 return 0;
}
