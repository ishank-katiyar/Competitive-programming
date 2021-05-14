#include <bits/stdc++.h>
using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  deque<int> d(n);
  int c1 = 0, c0 = 0;
  for (auto& i: d) {
   cin >> i;
   if (i == 1) c1++;
   else c0++;
  }
  if (c1 % 2 == 1) c1--;
  cout << max(c1, c0) << '\n';
  if (c1 >= n / 2) while (c1--) cout << 1 << ' ';
  else while (c0--) cout << 0 << ' ';
  cout << '\n';
 }
 return 0;
}
