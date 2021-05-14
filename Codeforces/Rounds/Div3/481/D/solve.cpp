#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 if (n <= 2) {
  cout << 0 << '\n';
  return 0;
 }
 vector<long long int> a(n);
 for (auto& i: a) cin >> i;
 int ans = 1e9;
 for (int I = -1; I <= 1; I++) {
  for (int J = -1; J <= 1; J++) {
   long long int a0 = a[0] + I;
   long long int a1 = a[1] + J;
   long long int d = a1 - a0;
   int cur_ans = abs(I) + abs(J);
   for (int i = 2; i < n; i++) {
    long long int aa = a0 + i * d;
    if (abs(a[i] - aa) <= 1) {
     cur_ans += abs(a[i] - aa); 
    }
    else {
     cur_ans = 1e9;
     break;
    }
   }
   ans = min(ans, cur_ans);
  }
 }
 if (ans == 1e9) ans = -1;
 cout << ans << '\n';
 return 0;
}
