#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() { return uniform_int_distribution<int>(1, (int)1e9)(rng); }

template <class A> A rnd(A x, A y) {
  return uniform_int_distribution<A>(x, y)(rng);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << 1 << '\n';
  int n = rnd(1, 5);
  while (n--)
    cout << rnd(0, 1);
  cout << '\n';
  return 0;
}
