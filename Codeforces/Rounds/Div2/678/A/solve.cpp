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
  int m; 
  cin >> m;
  int sum = 0;
  for (int i = 0; i < n; i++) {
   int x; 
   cin >> x;
   sum += x;
  }
  cout << (sum == m ? "YES" : "NO") << '\n';
 }
 return 0;
}
