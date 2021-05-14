#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 int x;
 cin >> x;
 vector<int64_t>  a (n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 function <int(const vector<int64_t>, const int64_t)> f = [&] (const vector<int64_t> A, const int64_t X) -> int {
  int N = int (A.size());
  if (N == 0) {
   return 0;
  }
  vector<int64_t> remaining (A);
  int64_t max_weight = 0;
  for (int mask = 1; mask < (1 << N); mask += 1) {
   int64_t cur_weight = 0;
   vector<int64_t> cur_remai;
   for (int i = 0; i < N; i++) {
    if ((mask >> i) & 1) {
     cur_weight += A[i];
    } else {
     cur_remai.push_back (A[i]);
    }
   }
   if (cur_weight > X) {
    continue;
   }
   if (int (cur_remai.size()) < int (remaining.size())) {
    max_weight = cur_weight;
    remaining = cur_remai;
   } else if (int (cur_remai.size()) == int (remaining.size()) && cur_weight > max_weight) {
    remaining = cur_remai;
    max_weight = cur_weight;
   }
  }
  assert (remaining != A);
  return 1 + f (remaining, X);
 }; 
 cout << f (a, x) << '\n';
 return 0;
}
