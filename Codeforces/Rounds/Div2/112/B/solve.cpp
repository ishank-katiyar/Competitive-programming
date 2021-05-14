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
 ll n;
 cin >> n;
 int k;
 cin >> k;
 auto f = [&] (ll mid) -> ll {
  ll ret = 0;
  int c = 0;
  while (1) {
   ll x = mid / bpow<ll, ll> (k, c);
   if (x == 0) break;
   ret += x;
   c++;
  }
  return ret;
 };
 ll low = 1, high = n;
 while (low < high) {
  ll mid = (low + high) >> 1;
  if (f(mid) >= n) high = mid;
  else low = mid + 1;
 }
 cout << low << '\n';
 return 0;
}
