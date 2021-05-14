#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = string(n, s[n-1]);
  set<char> st(s.begin(), s.end());
  if((int) st.size() == 1) {
   ans = string(n, s[0]);
  }
  cout << ans << '\n';
 }
}
