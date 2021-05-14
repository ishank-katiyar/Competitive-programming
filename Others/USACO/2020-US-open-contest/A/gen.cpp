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
 int N = rnd (2, 10);
 cout << N << '\n';
 string s = "";
 for (int i = 1; i <= N; i++) {
  s += (rnd (0, 1) + '0');
 }
 while (count (s.begin(), s.end(), '0') < 2) {
  s[rnd (0, N - 1)] = '0';
 }
 assert (count (s.begin(), s.end(), '0') >= 2);
 cout << s << '\n';
 return 0;
}
