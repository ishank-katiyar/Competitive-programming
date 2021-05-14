#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector <int> A (n);
  for (int i = 0; i < n; i++) {
   cin >> A[i];
  }
  vector<int> depth (n);

  function<void(const vector<int>, int, int, int)> f = [&] (const vector<int> a, int i, int j, int d) {
   if (i > j) return;
   int mx = 0;
   int idx = -1;
   for (int k = i; k <= j; k++) {
    if (a[k] > mx) {
     mx = a[k];
     idx = k;
    }
   }
   depth[idx] = d + 1;
   f (a, i, idx - 1, depth[idx]);
   f (a, idx + 1, j, depth[idx]);
  };

  f (A, 0, n - 1, -1);

  for (int i = 0; i < n; i++) {
   cout << depth[i] << ' ';
  }
  cout << '\n';
 }
 return 0;
}
