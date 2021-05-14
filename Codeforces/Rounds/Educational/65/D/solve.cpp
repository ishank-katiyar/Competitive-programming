#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 string s;
 cin >> s;
 vector<pair<char, int>> st;
 vector<int> ans(n, -1);
 bool x = false;
 for (int i = 0; i < n; i++) {
  if (st.empty() == true) {
   st.emplace_back(s[i], i);
    x ^= 1;
  }
  else {
   if (st.back().first == '(' && s[i] == ')') {
    ans[st.back().second] = ans[i] = x;
    x ^= 1;
    st.pop_back();
   }
   else {
    st.emplace_back(s[i], i);
    x ^= 1;
   }
  }
 }
 assert(st.empty() == true);
 for (auto& i: ans) cout << i;
 cout << '\n';
 return 0;
}
