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
  int64_t sum = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   sum += x;
  }
  cout << (sum % 2 == 0 ? "1" : "2") << '\n';
 }
 return 0;
}
