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
  long long int a, b, c;
  cin >> a >> b >> c;
  cout << a + b + c - 1 << '\n';
 }
 return 0;
}
