#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string a, b;
  cin >> a >> b;
  int n = (int) a.size();
  vector<int> A, B;
  for (int i = 0; i < n; i++) {
   if (a[i] == b[i]) continue;
   if (i % 2 == 0) {
    A.push_back (i);
   }
   else {
    B.push_back (i);
   }
  }
  int sz1 = (int) A.size();
  int ans1 = (sz1 > 0);
  for (int i = 1; i < sz1; i++) {
   if (A[i] - A[i - 1] != 2) ans1++;
  }
  int sz2 = (int) B.size();
  int ans2 = (sz2 > 0);
  for (int i = 1; i < sz2; i++) {
   if (B[i] - B[i - 1] != 2) ans2++;
  }
  cout << ans1 + ans2 << '\n';
 }
 return 0;
}
