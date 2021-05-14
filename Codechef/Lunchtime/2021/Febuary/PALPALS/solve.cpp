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
  vector<int> a (26);
  for (auto& i: s) {
   a[i - 'a']++;
  }
  int cnt1 = 0;
  int ext = 0;
  for (auto& i: a) {
   if (i == 1) {
    cnt1 += 1;
   } 
   if (i % 2 == 0 && i > 0) {
    ext += (i) / 2;
   }
   if (i % 2 == 1 && i > 3) {
    ext += (i - 3) / 2;
   }
  }
  cout << (cnt1 <= ext ? "YES" : "NO") << '\n';
 }
 return 0;
}
