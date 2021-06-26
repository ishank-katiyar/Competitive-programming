#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() {
 return uniform_int_distribution<int> (1, static_cast<int> (1e9)) (rng);
}

template<class A> 
A rnd(A x, A y) {
 return uniform_int_distribution<A> (x, y) (rng);
}

int main() 
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n = rnd (static_cast <int> (2e5), static_cast <int> (2e5));
 cout << n << '\n';
 for (int i = 0; i < n; i++) cout << rnd (1, static_cast <int> (1e6)) << ' ';
 cout << '\n';
 return 0;
}
