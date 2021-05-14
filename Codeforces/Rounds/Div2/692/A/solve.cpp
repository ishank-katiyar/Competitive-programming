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
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
   if (s[i] == ')') cnt++;
   else break;
  }
  cout << (cnt > n - cnt ? "Yes" : "No") << '\n';
 }
 return 0;
}
