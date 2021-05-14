#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int odd1 = 0, odd2 = 0;
  for (int i = 0; i < n; i++) {
   if (i % 2 == 0) {
    if ((s[i] - '0') % 2 == 1) odd1++;
   }
   else {
    if ((s[i] - '0') % 2 == 1) odd2++;
   }
  }
  if (n % 2 == 1) {
   if (odd1 > 0) cout << 1 << '\n';
   else cout << 2 << '\n';
  }
  else {
   if (odd2 > 0) cout << 2 << '\n';
   else cout << 1 << '\n';
  }
 }
 return 0;
}
