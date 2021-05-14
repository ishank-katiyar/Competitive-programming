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
 int t = 1;
 cout << t << '\n';
 int l = rnd (1, 100);
 int r = rnd (100, 100000);
 assert (r >= l);
 cout << l << ' ' << r << '\n';
 return 0;
}
