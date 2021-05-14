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
  bool ok = false;
  const string S = "2020";
  if (s == "2020") ok = true;
  if (s.substr (0, 4) == S) ok = true;
  if (s.substr (n - 4) == S) ok = true;
  if (s[0] + s.substr (n - 3) == S) ok = true;
  if (s.substr (0, 2) + s.substr (n - 2) == S) ok = true;
  if (s.substr (0, 3) + s.substr (n - 1) == S) ok = true;
  cout << (ok ? "YES" : "NO") << '\n';
 }
 return 0;
}
