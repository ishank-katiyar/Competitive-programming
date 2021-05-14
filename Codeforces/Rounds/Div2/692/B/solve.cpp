#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long n;
  cin >> n;

  auto check = [] (long long N) -> bool { 
   long long nn = N;
   while (nn > 0) {
    if (nn % 10) {
     if (N % (nn % 10) != 0) return false;
    }
    nn /= 10;
   }
   return true;
  };

  while (check (n) == false) n++;
  cout << n << '\n';
 }
 return 0;
}
