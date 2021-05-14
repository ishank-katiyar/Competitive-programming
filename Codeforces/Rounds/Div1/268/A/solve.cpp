#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 if (n < 4) {
  cout << "NO" << '\n';
  return 0;
 }
 cout << "YES" << '\n';
 while (n > 5) {
  cout << n << " - " << n - 1 << " = " << "1" << '\n';
  cout << "1 * 1 = 1" << '\n';
  n -= 2;
 }
 if (n == 4) {
  cout << "1 * 2 = 2" << '\n';
  cout << "2 * 3 = 6" << '\n';
  cout << "6 * 4 = 24" << '\n';
 }
 else if (n == 5) {
  cout << "5 - 1 = 4" << '\n';
  cout << "4 - 2 = 2" << '\n';
  cout << "2 * 3 = 6" << '\n';
  cout << "6 * 4 = 24" << '\n';
 }
 return 0;
}
