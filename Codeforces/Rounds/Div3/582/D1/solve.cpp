#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n, k;
 cin >> n >> k;
 vector<int> a(n);
 for (auto& i: a) cin >> i;
 auto f = [&] (int A) -> int {
  vector<int> moves;
  for (int i = 0; i < n; i++) {
   int aa = a[i];
   int cnt = 0;
   while (aa > A) {
    aa >>= 1;
    cnt++;
   }
   if (aa == A) moves.push_back(cnt);
  }
  sort(moves.begin(), moves.end());
  int ret = 0;
  if ((int) moves.size() < k) return 1e9;
  for (int i = 0; i < k; i++) ret += moves[i];
  return ret;
 };
 int ans = 1e9;
 for (int i = 0; i < 2e5; i++) {
  ans = min(ans, f(i));
 }
 cout << ans << '\n';
 return 0;
}
