#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  int n1 = n;
  vector<int> a(26);
  while(n1--) {
   string s;
   cin >> s;
   for(auto& i: s) a[i - 'a']++;
  }
  bool ok = true;
  for(auto& i: a) ok &= (i % n == 0);
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
