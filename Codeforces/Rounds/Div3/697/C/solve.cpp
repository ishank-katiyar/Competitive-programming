#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> A (k);
  map <int, int> mpa;
  for (int i = 0; i < k; i++) {
   cin >> A[i];
   mpa[A[i]]++;
  }
  vector<int> B (k);
  map <int, int> mpb;
  for (int i = 0; i < k; i++) {
   cin >> B[i];
   mpb[B[i]]++;
  }
  int64_t ans = 0;
  for (int i = 0; i < k; i++) {
   ans += (k - mpa[A[i]] - mpb[B[i]] + 1);
  }
  cout << ans / 2 << '\n';
 }
 return 0;
}
