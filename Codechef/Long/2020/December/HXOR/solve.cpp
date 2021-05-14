#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, x;
  cin >> n >> x;
  vector<int> a (n);
  vector<deque<int>> A (31);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   for (int j = 30; j >= 0; j--) {
    if ((a[i] >> j) & 1) {
     A[j].push_back (i);
    }
   }
  }
  int total = 0;
  for (int i = 0; i < n - 1; i++) {
   for (int j = 30; j >= 0; j--) {
    if ((a[i] >> j) & 1) {
     if (x == 0) continue;
     assert (A[j][0] == i);
     if (int(A[j].size()) == 1) {
      A[j].pop_front();
      a[i] ^= (1 << j);
      a[n - 1] ^= (1 << j);
     } else {
      A[j].pop_front();
      a[i] ^= (1 << j);
      int idx = A[j][0];
      A[j].pop_front();
      a[idx] ^= (1 << j);
     }
     x--;
     total++;
    }
   }
  }
  if (total <= 0 && n > 2 && x == 1) {
   a[n - 2] ^= 1;
   a[n - 1] ^= 1;
  }
  if (n == 2 && x % 2 == 1) {
   a[n - 2] ^= 1;
   a[n - 1] ^= 1;
  }
  for (int i = 0; i < n; i++) {
   cout << a[i] << ' ';
  }
  cout << '\n';
 }
 return 0;
}
