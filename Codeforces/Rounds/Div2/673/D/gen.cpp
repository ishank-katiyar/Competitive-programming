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
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 int t = 1;
 cout << t << '\n';
 int n = rnd(1, 10000);
 cout << n << '\n';
 int sum = 100000;
 while (n > 1) {
  int x = rnd(1, 10);
  cout << x << ' ';
  sum += x;
  n--;
 } 
 assert (sum > 0);
 cout << sum << '\n';
 return 0;
}
