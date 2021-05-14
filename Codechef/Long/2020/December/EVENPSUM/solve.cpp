#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long A, B;
  cin >> A >> B;
  cout << ((A + 1) / 2) * ((B + 1) / 2) + (A / 2) * (B / 2) << '\n';
 }
 return 0;
}
