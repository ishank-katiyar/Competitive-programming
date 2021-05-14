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
  vector<int> a(n);
  for(auto& i: a) cin >> i;
  vector<int> b(a);
  sort(b.begin(), b.end());
  bool ok = true;
  for(int i = 0; i < n; i++) {
   if(a[i] != b[i] && a[i] % b[0]) ok = false;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}
