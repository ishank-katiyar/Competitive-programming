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
  vector<int> odd, even;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   (x % 2 == 0 ? even : odd).push_back (x);
  }
  while (even.size() > 0) {
   cout << even.back() << ' ';
   even.pop_back();
  }
  while (odd.size() > 0) {
   cout << odd.back() << ' ';
   odd.pop_back();
  }
  cout << '\n';
 }
 return 0;
}
