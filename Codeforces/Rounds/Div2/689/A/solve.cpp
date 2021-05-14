#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  string s = "";
  for (int i = 0; i < n; i++) {
   if (i % 3 == 0) s += 'a';
   else if (i % 3 == 1) s += "b";
   else s += "c";
  }
  cout << s << '\n';
 }
 return 0;
}
