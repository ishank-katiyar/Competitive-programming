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
  string b;
  cin >> b;
  string a = "";
  string d = "";
  if (b[0] == '1') d = "2", a = "1";
  if (b[0] == '0') d = "1", a = "1";
  for (int i = 1; i < n; i++) {
   if (1 + int (b[i] - '0') == int(d[i - 1] - '0')) {
    a += "0";
    d += b[i];
   } else {
    a += "1";
    d += to_string (1 + int(b[i] - '0'));
   }
  }
  cout << a << '\n';
  // cout << d << '\n';
 }
 return 0;
}
