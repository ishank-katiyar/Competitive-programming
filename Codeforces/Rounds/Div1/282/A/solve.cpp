#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 string s;
 cin >> s;
 int n = (int) s.size();
 int idx = -1;
 for (int i = 0; i < n; i++) {
  if (s[i] == '#') {
   idx = i;
  }
 }
 assert (idx != -1);
 int bal_last = 0;
 int mn_bal = 0;
 for (int i = idx + 1; i < n; i++) {
  assert (s[i] != '#');
  if (s[i] == '(') bal_last++;
  else bal_last--;
  mn_bal = min (mn_bal, bal_last);
 }
 int bal = 0;
 vector<int> ans;

 auto ret = []() {
  cout << -1 << '\n';
  exit(0);
 };

 for (int i = 0; i < n; i++) {
  if (i == idx) {
   int new_add = bal + bal_last;
   new_add = max (new_add, 1);
   bal -= new_add;
   if (bal + mn_bal < 0) {
    ret();
   }
   ans.push_back(new_add);
   bal = 0;
   break;
  }
  if (s[i] == '(') bal++;
  else if (s[i] == ')') bal--;
  if (s[i] == '#') {
   bal--;
   ans.push_back(1);
  }
  if (bal < 0) ret();
 }
 for (auto& i: ans) cout << i << '\n';
 return 0;
}
