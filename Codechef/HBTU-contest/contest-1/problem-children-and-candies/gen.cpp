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
 cout << 1 << '\n';
 int N = rnd (1, static_cast <int> (1e5));
 int M = rnd (1, static_cast <int> (1e5));
 cout << N << ' ' << M << '\n';
 for (int i = 0; i < N; i++) cout << rnd (1, static_cast <int> (1e5)) << ' ';
 cout << '\n';
 for (int i = 0; i < M; i++) cout << rnd (1, static_cast <int> (1e5)) << ' ';
 cout << '\n';
 return 0;
}
