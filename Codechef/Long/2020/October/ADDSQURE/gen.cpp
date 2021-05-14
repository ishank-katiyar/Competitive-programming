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
 int W, H, n, m;
 W = rnd(1, 100);
 H = rnd(1, 100);
 n = rnd(1, W);
 m = rnd(1, H);
 cout << W << ' ' << H << ' ' << n << ' ' << m << '\n';
 map<int, int> mp;
 while (n--) {
  while (1) {
   int x = rnd(0, W);
   if (mp.count(x)) continue;
   cout << x << ' ';
   mp[x] = 1;
   break;
  }
 }
 cout << '\n';
 mp.clear();
 while (m--) {
  while (1) {
   int x = rnd(0, H);
   if (mp.count(x)) continue;
   cout << x << ' ';
   mp[x] = 1;
   break;
  }
 }
 cout << '\n';
 return 0;
}
