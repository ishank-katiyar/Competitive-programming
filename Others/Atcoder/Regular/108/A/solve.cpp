#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 long long s, p;
 cin >> s >> p;
 for (long long i = 1; i * i <= p; i++) {
  if (p % i) continue;
  if (i + (p / i) == s) {
   cout << "Yes" << '\n';
   // cout << i << ' ' << p / i << '\n';
   return 0;
  }
 }
 cout << "No" << '\n';
 return 0;
}
