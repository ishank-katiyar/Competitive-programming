#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 if (n > 5) {
  cout << "1 2\n1 3\n1 4\n4 5\n4 6\n";
  for (int i = 7; i <= n; i++) cout << "1 " << i << '\n'; 
 }
 else cout << -1 << '\n';
 for (int i = 2; i <= n; i++) cout << 1 << ' ' << i << '\n';
 return 0;
}
