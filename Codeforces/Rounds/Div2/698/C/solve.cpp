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
  vector<int64_t> A (2 * n);
  bool ok = true;
  for (int i = 0; i < 2 * n; i++) {
   cin >> A[i];
   if (ok) {
    if (A[i] % 2) ok = false;
    A[i] /= 2;
   }
  }
  if (ok == false) {
   cout << "NO" << '\n';
   continue;
  }
  sort (A.begin(), A.end());
  debug (A);
  for (int i = 0; i < 2 * n; i += 2) {
   ok &= (A[i] == A[i + 1]);
  }
  if (ok == false) {
   cout << "NO" << '\n';
   continue;
  }
  int64_t suf = 0;
  set<int64_t> a;
  int idx = n;
  for (int i = 2 * n - 1; i >= 0; i -= 2) {
   A[i] -= suf;
   if (A[i] % idx) {
    ok = false;
    break;
   }
   A[i] /= idx;
   a.insert(A[i]);
   suf += A[i];
   idx--;
  }
  debug (a);
  ok &= ((*a.begin()) > 0);
  ok &= (static_cast <int> (a.size()) == n);
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
