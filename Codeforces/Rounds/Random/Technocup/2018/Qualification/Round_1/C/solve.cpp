#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 string s;
 cin >> s;
 set<char> st;
 int sz = 0;
 string ans = "";

 auto ok = [] (char ch) -> bool {
  return (ch != 'a') && (ch != 'e') && (ch != 'i') && (ch != 'o') && (ch != 'u');
 };
 
 for (int i = 0; i < (int) s.size(); i++) {
  if (ok(s[i])) {
   sz++;
   st.insert (s[i]);
   if (sz >= 3 && (int) st.size() > 1) {
    ans += " ";
    ans += s[i];
    st.clear();
    st.insert (s[i]);
    sz = 1;
   }
   else ans += s[i];
  }
  else {
   ans += s[i];
   sz = 0;
   st.clear();
  }
 }
 cout << ans << '\n';
 
 return 0;
}
