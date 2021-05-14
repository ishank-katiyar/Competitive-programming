#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  vector<int> C (3);
  for (auto& i: C) cin >> i;
  vector<int>  A (5);
  for (auto& i: A) cin >> i;
  bool ok = true;
  C[0] -= A[0];
  C[1] -= A[1];
  C[2] -= A[2];
  for (int i = 0; i < 3; i++) {
   A[i] = 0;
   if (C [i] < 0) ok = false;
  }
  if (ok == false) {
   cout << "NO" << '\n';
   continue;
  }
  int mn = min (C[0], A[3]);
  C[0] -= mn;
  A[3] -= mn;
  mn = min (C[2], A[3]);
  C[2] -= mn;
  A[3] -= mn;
  if (A[3] > 0) {
   ok = false;
   cout << "NO" << '\n';
   continue;
  }
  mn = min (C[1], A[4]);
  C[1] -= mn;
  A[4] -= mn;
  mn = min (C[2], A[4]);
  C[2] -= mn;
  A[4] -= mn;
  if (A[4] > 0) {
   ok = false;
   cout << "NO" << '\n';
   continue;
  }
  cout << "YES" << '\n';
 }
 return 0;
}
