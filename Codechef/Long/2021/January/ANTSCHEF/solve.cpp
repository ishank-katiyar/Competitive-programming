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
  assert (n == 1);
  int sz;
  cin >> sz;
  int64_t cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < sz; i++) {
   int x;
   cin >> x;
   (x < 0 ? cnt0 : cnt1) += 1;
  }
  cout << cnt0 * cnt1 << '\n';
 }
 return 0;
}
