#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 long long int a, b, f, k;
 cin >> a >> b >> f >> k;
 if (b < f || b < a - f) {
  cout << -1 << '\n';
  return 0;
 }
 if (k > 1 && b < 2 * (a - f)) {
  cout << -1 << '\n';
  return 0;
 }
 if (k > 2 && b < 2 * f) {
  cout << -1 << '\n';
  return 0;
 }
 long long int ans = 0;
 long long int total_dist = a * k - f;
 long long int tank = b - f;
 bool ok = false;
 while (total_dist > 0) {
  if (ok) {
   if (total_dist <= 2 * f) {
    if (tank < total_dist) {
     ans++;
    }
    break;
   }
   if (tank < 2 * f) {
    ans++; 
    tank = b - 2 * f;
   }
   else tank -= 2 * f;
   total_dist -= 2 * f;
   ok ^= 1;
  }
  else {
   if (total_dist < 2 * (a - f)) {
    if (tank < total_dist) ans++;
    break;
   }
   if (tank < 2 * (a - f)) {
    ans++;
    tank = b - 2 * (a - f);
   } 
   else tank -= 2 * (a - f);
   total_dist -= 2 * (a - f);
   ok ^= 1;
  }
 }
 cout << ans << '\n';
 return 0;
}
