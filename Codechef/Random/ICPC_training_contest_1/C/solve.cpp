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
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  map <int, vector<pair<int, int>>> mp;
  for (int i = 0; i < n; i++) {
   int l, r, v;
   cin >> l >> r >> v;
   assert (l <= r);
   mp[v].emplace_back (l, r);
  }

  auto intersect = [] (pair<int, int> a, pair<int, int> b) -> bool {
   return (b.first >= a.first && b.first <= a.second) || (b.second >= a.first && b.second <= a.second);
  };

  bool ok = true;
  for (auto& i: mp) {
   int N = static_cast <int> (i.second.size());
   DSU D (N);
   for (int k = 0; k < N; k++) {
    for (int j = k + 1; j < N; j++) {
     if (intersect (i.second[k], i.second[j])) {
      D.Union (k, j);
     }
    }
   }
   map <int, int> mm;
   for (int j = 0; j < N; j++) mm[D.rep (j)]++;
   debug (mm);
   bool cur_ok = true;
   for (auto& j: mm) {
    cur_ok &= (j.second <= 2);
   }
   ok &= cur_ok;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
