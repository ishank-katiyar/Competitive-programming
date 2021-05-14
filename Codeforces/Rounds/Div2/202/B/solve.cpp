#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int V;
 cin >> V;
 vector<int> a (9);
 int digit = -1, cnt = 0, remai = 0;
 for (int i = 0; i < 9; i++) {
  cin >> a[i];
  int cur_cnt = V / a[i];
  if (cur_cnt >= cnt) {
   digit = i + 1;
   cnt = cur_cnt;
   remai = V % a[i];
  }
 }
 if (cnt == 0) {
  cout << -1 << '\n';
  return 0;
 }
 string ans = string (cnt, '0' + digit);
 for (auto& i: ans) {
  for (int j = 9; j > digit; j--) {
   int extracost = a[j - 1] - a[digit - 1];
   if (extracost <= remai) {
    i = j + '0';
    remai -= extracost;
    break;
   }
  }
 }
 remai = 0;
 digit = -1;
 for (int i = 0; i < 9; i++) {
  if (V / a[i] == cnt) {
   if (V % a[i] > remai) {
    remai = V % a[i];
    digit = i + 1;
   }
  }
 }
 if (digit == -1) {
  cout << ans << '\n';
  return 0;
 }
 string ans1 = string (cnt, '0' + digit);
 for (auto& i: ans1) {
  for (int j = 9; j > digit; j--) {
   int extracost = a[j - 1] - a[digit - 1];
   if (extracost <= remai) {
    i = j + '0';
    remai -= extracost;
    break;
   }
  }
 }
 cout << max (ans, ans1) << '\n';
 return 0;
}
