#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  deque<int> d;
  for (int i = 1; i <= n; i++) d.push_back(i);
  vector<pair<int, int>> ans;
  while (1) {
   if ((int) d.size() <= 1) break;
   int a = d.back();
   d.pop_back();
   int b = d.back();
   d.pop_back();
   ans.emplace_back(a, b);
   d.push_back((a + b + 1) / 2);
  }
  assert (d.empty() == false);
  cout << d.front() << '\n';
  assert ((int) ans.size() == n - 1);
  for (auto& i: ans) cout << i.first << ' ' << i.second << '\n';
 }
 return 0;
}
