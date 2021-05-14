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
  vector<char> ss;
  for (int i = 0; i < n; i++) {
   if (i % 2 == 0) {
    if (s[i] == '1') {
     ss.push_back ('(');
    } else {
     ss.push_back (')');
    }
   } else {
    if (s[i] == '1') {
     ss.push_back (')');
    } else {
     ss.push_back ('(');
    }
   }
  }
  vector<char> S;
  for (auto& i: ss) {
   if (S.empty() == true) {
    S.push_back (i);
   } else {
    if (S.back() == '(' && i == ')') {
     S.pop_back();
    } else {
     S.push_back (i);
    }
   }
  }
  if (S.empty() == false) {
   cout << "NO" << '\n';
   continue;
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
   cout << (i % 2 == 0 ? "(" : ")");
  }
  cout << '\n';
  for (auto& i: ss) {
   cout << i;
  }
  cout << '\n';
 }
 return 0;
}
