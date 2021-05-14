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
  if (count (s.begin(), s.end(), s[n - 1]) == 1) cout << "NO";
  else cout << "YES";
  cout << '\n';
 }
 return 0;
}
