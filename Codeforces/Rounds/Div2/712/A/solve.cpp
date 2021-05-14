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
  auto palin = [] (string S) -> bool {
   string SS (S);
   reverse (SS.begin(), SS.end());
   return S == SS;
  };
  if (s.front() != 'a' || palin (s + "a") == false) {
   cout << "YES\n" << s << "a" << '\n';
  } else {
   if (count (s.begin(), s.end(), 'a') != static_cast <int> (s.size())) {
    cout << "YES\n" << "a" << s << '\n';
   } else {
    cout << "NO" << '\n';
   }
  }
 }
 return 0;
}
