#include <bits/stdc++.h>

using namespace std;

template<class X, class Y>
X bpow(X a , Y b, int mod = -1) {
  X res(1);
  if (mod != -1) {
    a %= mod;
  }
  while(b) {
    if(b % 2 == 1) {
      if (mod != -1) {
        (res *= a) %= mod;
      } else {
        res *= a;
      }
    }
    if (mod != -1) {
      (a *= a) %= mod;
    } else {
      a *= a;
    }
    b /= 2;
  }
  return res;
  /*
  * Original
  X res(1);
  while(b) {
  if(b % 2 == 1) res *= a;
  a *= a;
  b /= 2;
  }
  return res;
  */
}

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    for (int i = 15; i >= 1; i--) {
      int64_t xx = (int64_t) 205 * bpow<int64_t, int64_t> (10, i);
      // cout << xx << '\n';
      ans += n / xx;
      n %= xx;
    }
    if (n != 0) {
      ans = -1;
    }
    // cout << (n == 0 ? "YES" : "NO") << '\n';
    cout << ans << '\n';
  }
  return 0;
}
