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
 int N = rnd <int> (50, 100);
 string S = "";
 S += to_string (rnd <int> (1, 9));
 for (int i = 2; i <= N; i++) {
  S += to_string (rnd<int> (0, 9));
 }
 cout << S;
 return 0;
}
