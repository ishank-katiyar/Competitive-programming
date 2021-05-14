#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 long long n;
 cin >> n;
 long long ans = 1;
 ans = pow (2, 4) * pow (3, 3) * pow (5, 2) * 7 * 11 * 13 * 17 * 19 * 23 * 29;
 // vector<int> aa = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
 // for (auto& i: aa) {
 //  int cnt = 0;
 //  long long N = n;
 //  while (N > 0) {
 //   cnt++;
 //   N /= i;
 //  }
 // 
 // }
 cout << ans + 1 << '\n';
 return 0;
}
