#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 vector<long long int> a(n);
 for (auto& i: a) cin >> i;
 int m;
 cin >> m;
 long long int ans = 0;
 for (int i = 0; i < m; i++) {
  int w, h;
  cin >> w >> h;
  long long int cur_ans = max(ans, a[w - 1]);
  cout << cur_ans << '\n';
  ans = cur_ans + h;
 }
 return 0;
}
