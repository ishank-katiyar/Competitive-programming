#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class X, class Y>
X bpow(X a , Y b) {
 X res(1);
 while(b) {
  if(b % 2 == 1) res *= a;
  a *= a;
  b /= 2;
 }
 return res;
}

int main() 
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t;
 cin >> t;
 vector<ll> pre;
 ll x = 1;
 while (x < (ll) 1e18) {
  pre.push_back(x);
  x *= 3;
 } 
 while (t--) {
  ll n;
  cin >> n;
  vector<int> c(100, 0);
  while (n) {
   int idx = upper_bound(pre.begin(), pre.end(), n) - pre.begin();
   assert (idx > 0);
   idx--;
   c[idx]++;
   n -= pre[idx];
  }
  while (1) {
   for (int i = 99; i >= 0; i--) {
    if (c[i] > 1) {
     c[i + 1]++;
     for (int j = i; j >= 0; j--) {
      c[j] = 0;
     }
     break;
    }
   }
   bool ok = true;
   for (int i = 0; i < 100; i++) if (c[i] > 1) ok = false;
   if (ok) break;
  }
  ll ans = 0;
  for (int i = 0; i < 100; i++) {
   ans += c[i] * bpow<ll, ll> (3, i);
  }
  cout << ans << '\n';
 }
 return 0;
}
