#include <bits/stdc++.h>

using namespace std;

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 int n;
 cin >> n;
 long long l, r;
 cin >> l >> r;
 long long Ql, Qr;
 cin >> Ql >> Qr;
 vector<long long> a(n);
 long long sum = 0;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
  sum += a[i];
 }
 long long ans = INT_MAX;
 ans = min (ans, sum * r + Qr * (n - 1));
 long long ss = 0;
 for (int i = 0; i < n; i++) {
  long long cur = 0;
  ss += a[i];
  cur += (ss * l) + ((sum - ss) * r);
  if (i + 1 >= (n - 1 - i)) {
   int cnt = i + 1 - (n - 1 - i);
   cnt--;
   cnt = max (cnt, 0);
   cur += cnt * Ql;
  }
  else {
   int cnt = n - 1 - i - (i + 1);
   cnt--;
   cnt = max (cnt, 0);
   cur += cnt * Qr;
  }
  //cerr << cur << endl;
  ans = min (ans, cur);
 }
 cout << ans << '\n';
 return 0;
}
