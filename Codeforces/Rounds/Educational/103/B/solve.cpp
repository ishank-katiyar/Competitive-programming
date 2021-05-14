#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }

  auto f = [] (vector<int64_t> A, int64_t M, int64_t K) -> bool {
   int N = static_cast <int> (A.size());
   A[0] += M;
   bool ok = true;
   int64_t pre = A[0];
   for (int i = 1; i < N; i++) {
    ok &= (K * pre - A[i] * 100 >= 0);
    pre += A[i];
   }
   return ok;
  };

  int64_t low = 0, high = 1e15;
  while (low < high) {
   int64_t mid = (low + high) / 2;
   if (f (a, mid, k) == false)  low = mid + 1;
   else high = mid;
  }
  cout << low << '\n';
 }
 return 0;
}
