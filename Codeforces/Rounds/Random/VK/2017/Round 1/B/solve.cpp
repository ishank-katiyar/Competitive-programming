#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int maxn = 52;
 vector<string> names;
 for (int i = 0; i < 26; i++) {
  string s;
  s += char('A' + i);
  names.push_back(s);
 }
 for (int i = 26; i < maxn; i++) {
  string s;
  s += char('A' + i - 26);
  s += "a";
  names.push_back(s);
 }
 //cout << (int) names.size() << '\n';
 //for (auto& i: names) cout << i << ' ';
 //cout << '\n';
 int n, k;
 cin >> n >> k;
 int c = 0;
 vector<string> ans;
 for (int i = 0; i < k - 1; i++) {
  ans.push_back(names[c++]);
 }
 n -= k;
 n++;
 while (n--) {
  string s;
  cin >> s;
  if (s == "YES") {
   ans.push_back(names[c++]);
  }
  else {
   int sz = (int) ans.size();
   ans.push_back(ans[sz - k + 1]);
  }
 }
 for (auto& i: ans) cout << i << ' ';
 cout << '\n';
 return 0;
}
