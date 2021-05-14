#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 string s;
 cin >> s;
 vector<char> ss;
 for (int i = 0; i < n; i++) {
  if (ss.empty() == true) {
   ss.push_back (s[i]);
  }
  else {
   int sz = (int) ss.size();
   if (sz > 1 && ss[sz - 2] == 'f' && ss[sz - 1] == 'o' && s[i] == 'x') {
    ss.pop_back();
    ss.pop_back();
   }
   else ss.push_back (s[i]);
  }
 }
 cout << (int) ss.size() << '\n';
 return 0;
}
