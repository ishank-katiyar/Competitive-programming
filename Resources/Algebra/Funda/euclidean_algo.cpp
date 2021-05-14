#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() { return uniform_int_distribution<int>(1, (int)1e9)(rng); }

template <class A> A rnd(A x, A y) {
  return uniform_int_distribution<A>(x, y)(rng);
}

namespace algebra {

template <class X, class Y> X bpow(X a, Y b, int mod = -1) {
  X res(1);
  if (mod != -1) {
    a %= mod;
  }
  while (b) {
    if (b % 2 == 1) {
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

template <class X = int64_t> X gcd(X a, X b) {
  if (!a || !b) {
    return a | b;
  }
  unsigned shift = __builtin_ctz(a | b);
  a >>= shift;
  do {
    b >>= __builtin_ctz(b);
    if (a > b) {
      swap(a, b);
    }
    b -= a;
  } while (b);
  return a << shift;
}

}; // namespace algebra

using namespace algebra;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int64_t a = (int64_t)1 << rnd(1, 40);
  int64_t b = (int64_t)1 << rnd(1, 40);
  cout << a << ' ' << b << '\n';
  /*
   * rule = gcd (a, b) = gcd (b, a ope b);
   * ope = any operation which doesnt add there factors together (like multiply,
   * divide) valid ope = %, + , - invalid ope = *, /
   */
  cout << gcd(10, 10) << '\n';
  cout << typeid(gcd(10, 10)).name() << '\n';
  cout << typeid(gcd(10, 1123424234224)).name() << '\n';
  cout << typeid(gcd(1123349872349, 1123349872349)).name() << '\n';
  cout << gcd(10, 10) << '\n';
  cout << gcd(10, 1123424234224) << '\n';
  cout << gcd(1123349872349, 1123349872349) << '\n';
  cout << gcd(a, b) << '\n';
  cout << __gcd(a, b) << '\n';
  return 0;
}
