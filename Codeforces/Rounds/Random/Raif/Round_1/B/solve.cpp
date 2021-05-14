#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int c1 = count (s.begin(), s.end(), '>');
  int c2 = count (s.begin(), s.end(), '<');
  int ans = 0;
  if (c1 == 0 || c2 == 0) {
   cout << n << '\n';
   continue;
  }
  if (s[0] == '-' || s[n - 1] == '-') ans++;
  for (int i = 0; i < n - 1; i++) {
   if (s[i] == '-' || s[i + 1] == '-') ans++; 
  }
  cout << ans << '\n';
 }
 return 0;
}
