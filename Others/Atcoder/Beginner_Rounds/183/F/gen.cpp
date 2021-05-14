#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() {
 return uniform_int_distribution<int> (1, (int) 1e9) (rng);
}

template<class A> 
A rnd(A x, A y) {
 return uniform_int_distribution<A> (x, y) (rng);
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 // int n = rnd (1, (int) 1e4);
 // int n = 20000;
 int n = 5;
 // int q = rnd (1, (int) 1e5);
 int q = n - 1;
 cout << n << ' ' << q << '\n';
 for (int i = 1; i <= n; i++) {
  // cout << rnd (1, n) << ' ';
  cout << i << ' ';
 }
 cout << '\n';
 // while (q--) {
 //  int type = rnd (1, 2);
 //  cout << type << ' ' << rnd (1, n) << ' ' << rnd (1, n) << '\n';
 // }
 for (int i = 1; i <= q; i++) {
  cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
 }
 return 0;
}
