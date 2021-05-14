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
 cout << 1 << '\n';
 int n = rnd (1, 15);
 cout << n << '\n';
 map <int, int> mp;
 while (n--) {
  int x = rnd (1, 100);
  while (mp.count (x) != 0) {
   x = rnd (1, 10);
  }
  cout << x << ' ';
  mp[x]++;
 }
 return 0;
}
