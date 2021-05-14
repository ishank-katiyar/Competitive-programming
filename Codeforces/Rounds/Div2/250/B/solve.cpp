#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int sum, limit;
 cin >> sum >> limit;
 map<int, vector<int>> mp;
 auto f = [&] (int n) -> int {
  int cnt = 0;
  while (n % 2 == 0) cnt++, n /= 2;
  return (1 << cnt);
 };
 for (int i = 1; i <= limit; i++) mp[f(i)].push_back(i);
 vector<int> ans;
 for (int i = 17; i >= 0; i--) {
  int cur_sum = 1 << i;
  int sz = sum / cur_sum;
  while (sz-- && mp[cur_sum].empty() == false) {
   int x = mp[cur_sum].back();
   sum -= cur_sum;
   ans.push_back(x);
   mp[cur_sum].pop_back();
  }
 } 
 if (sum) cout << -1 << '\n';
 else {
  cout << (int) ans.size() << '\n';
  for (auto& i: ans) cout << i << ' ';
  cout << '\n';
 }
 return 0;
}
