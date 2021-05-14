#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int n;
 cin >> n;
 long long int k;
 cin >> k;
 __int128 K = k;
 vector<long long int> a(n);
 for (auto& i: a) cin >> i;
 vector<long long int> b(n);
 for (auto& i: b) cin >> i;


 vector<__int128> A(n);
 for (int i = 0; i < n; i++) A[i] = a[i];
 vector<__int128> B(n);
 for (int i = 0; i < n; i++) B[i] = b[i];
 auto f = [&] (__int128 M) -> bool {
  __int128 extra = 0;
  for (int i = 0; i < n; i++) {
   extra += min((__int128) 0, B[i] - A[i] * M);
  }
  extra *= -1;
  //cout << M << ' ' << extra << '\n';
  return K >= extra;
 };
 
 __int128 low = 0, high = 2e9;
 while (low < high) {
  long long int mid = (low + high) >> 1;
  if (f(mid) == false) high = mid;
  else low = mid + 1;
 }
 //cout << low << '\n';
 if (f(low) == false) low--;
 long long int ans = low;
 cout << ans << '\n';
 return 0;
}
