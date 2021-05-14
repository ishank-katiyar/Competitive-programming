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
 vector<long long int> a(n);
 for (auto& i: a) cin >> i;
 vector<long long int> b(n);
 for (auto& i: b) cin >> i;

 auto f = [&] (long long int M) -> bool {
  long long int extra = 0;
  for (int i = 0; i < n; i++) {
   extra += min(0LL, b[i] - a[i] * M);
  }
  extra *= -1;
  //cout << M << ' ' << extra << '\n';
  return k >= extra;
 };
 
 long long int low = 0, high = 1e9;
 while (low < high) {
  long long int mid = (low + high) >> 1;
  if (f(mid) == false) high = mid;
  else low = mid + 1;
 }
 //cout << low << '\n';
 if (f(low) == false) low--;
 cout << low << '\n';
 return 0;
}
