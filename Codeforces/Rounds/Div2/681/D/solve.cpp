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
  int N;
  cin >> N;
  vector<long long int> B (N);
  for (auto& i: B) cin >> i;

  auto f = [] (vector<long long int> A) -> bool {
   int n = (int) A.size();
   vector<long long> a (n);
   a[0] = 1;
   for (int i = 1; i < n; i++) {
    if (A[i] > A[i - 1]) a[i] = a[i - 1] + 1;
    else a[i] = 1;
   }
   debug (a);
   vector<vector<long long>> all;
   vector<long long> cur;
   for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
     if ((int) cur.size() > 1) all.push_back (cur);
     cur.clear();
     cur.push_back (A[i]);
    }
    else cur.push_back (A[i]);
   }
   // if ((int) cur.size() > 1) all.push_back (cur);
   debug (all);
   vector<long long> last = cur;
   debug (last);
   // debug (all);
   long long sum = 0;
   for (auto& i: all) {
    assert ((int) i.size() > 1);
    int sz = (int) i.size();
    sum += i[sz - 1] - i[0];
   }
   long long x = last[0];
   debug (sum, x);
   return sum <= x;
  };

  bool ok = f (B);
  reverse (B.begin(), B.end());
  ok |= f (B);
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
