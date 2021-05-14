#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 long double X;
 cin >> X;
 long double sum = 0;
 for (int i = 0; i < n; i++) {
  long double a, b;
  cin >> a >> b;
  sum += (a * b) / 100;
  if (sum - X >= 1e-6) {
   cout << i + 1 << '\n';
   return 0;
  }
 }
 cout << -1 << '\n';
 return 0;
}
