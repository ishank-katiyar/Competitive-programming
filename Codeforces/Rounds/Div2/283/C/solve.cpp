#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, m;
 cin >> n >> m;
 vector<string> a(n);
 for (auto& i: a) cin >> i;
 vector<string> ans(n);
 
 auto check = [&] (vector<string> A) -> bool {
  vector<string> b(A);
  sort (b.begin(), b.end());
  return A == b;
 };

 for (int j = 0; j < m; j++) {
  vector<string> cur_ans(ans);
  for (int i = 0; i < n; i++) {
   cur_ans[i] += a[i][j];
  }
  if (check(cur_ans) == true) ans = cur_ans;
 }
 cout << m - (int) ans[0].size() << '\n';
 return 0;
}
