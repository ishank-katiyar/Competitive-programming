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
 string t;
 cin >> t;
 int ca = count(s.begin(), s.end(), 'a') + count(t.begin(), t.end(), 'a');
 int cb = count(s.begin(), s.end(), 'b') + count(t.begin(), t.end(), 'b');
 if (ca % 2 == 1 || cb % 2 == 1) {
  cout << -1 << '\n';
  return 0;
 } 
 vector<int> idx1, idx2;
 for (int i = 0; i < n; i++) {
  if (s[i] != t[i]) {
   if (s[i] == 'a') idx1.push_back(i + 1);
   else idx2.push_back(i + 1);
  }
 }
 vector<pair<int, int>> ans;
 while ((int) idx1.size() >= 2) {
  int x = idx1.back();
  idx1.pop_back();
  int y = idx1.back();
  idx1.pop_back();
  ans.emplace_back(x, y);
 }
 while ((int) idx2.size() >= 2) {
  int x = idx2.back();
  idx2.pop_back();
  int y = idx2.back();
  idx2.pop_back();
  ans.emplace_back(x, y);
 }
 if (idx1.empty() == false) {
  assert (idx2.empty() == false);
  int x = idx1.back();
  int y = idx2.back();
  ans.emplace_back(x, x);
  ans.emplace_back(x, y);
 }
 cout << (int) ans.size() << '\n';
 for (auto& i: ans) cout << i.first << ' ' << i.second << '\n';
 return 0;
}
