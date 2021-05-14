#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;

  auto f = [] (const vector<int> a) -> bool {
   assert (is_sorted (a.begin(), a.end()));
   int N = static_cast <int> (a.size());
   for (int i = 1; i < N; i++) {
    if (a[i] - a[i - 1] <= 1) {
     return false;
    }
   }
   return true;
  };

  bool ok = false;
  int n = static_cast <int> (s.size());
  for (int i = 1; i <= n; i++) {
   vector<int> a;
   for (int j = 1; j <= i; j++) {
    if (s[j - 1] == '1') {
     a.push_back (j);
    }
   }
   for (int j = i + 1; j <= n; j++) {
    if (s[j - 1] == '0') {
     a.push_back (j);
    }
   }
   ok |= f (a);
  }

  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
