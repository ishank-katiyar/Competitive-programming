#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int N, K;
  cin >> N >> K;
  vector<int> ans (N + 1);
  int neg = N - K;
  int parity = -1;
  if (neg <= K) parity = 1;
  else parity = 0, neg = K;
  for (int i = 1; i <= N; i++) {
   if (neg && i % 2 == parity) {
    ans[i] = (parity ? -i : i); 
    neg--;
   } else {
    ans[i] = (parity ? i : -i);
   }
  }
  int sum = 0;
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
   sum += ans[i];
   if (sum > 0) cnt++;
   cout << ans[i];
   if (i < N) cout << ' ';
   else cout << '\n';
  }
  assert (cnt == K);
 }
 return 0;
}
