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
  vector<int64_t> a (n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  cout << 2 * (*max_element (a.begin(), a.end()) - *min_element (a.begin(), a.end())) << '\n';
 }
 return 0;
}
