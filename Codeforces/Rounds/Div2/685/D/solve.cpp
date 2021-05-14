#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long d, k;
  cin >> d >> k;
  long long value = (d * d) / (k * k);
  string ans = "";
  for (long long i = 1; i <= 2 * d; i++) {
   long long first = i / 2;
   long long second = i - first;
   long long v = first * first + second * second;
   if (v > value) {
    if (i % 2 == 1) {
     ans = "Utkarsh";
    }
    else ans = "Ashish";
    break;
   }
  }
  cout << ans << '\n';
 }
 return 0;
}
