#include <bits/stdc++.h>
using namespace std;

bool f(string s) {
 string ss(s);
 reverse(ss.begin(), ss.end());
 return ss == s;
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string s;
 cin >> s;
 int n = (int) s.size();
 vector<string> a;
 for(int mask = 1; mask < (1 << n); mask++) {
  string ss = "";
  for(int i = 0; i < n; i++) {
   if((mask >> i) & 1) ss += s[i];
  }
  if(f(ss)) a.push_back(ss);
 }
 sort(a.rbegin(), a.rend());
 cout << a[0] << '\n';
}
