#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	const int x = 100;
	cout << rnd (0, x) << ' ' << rnd (0, x) << ' ' << rnd (0, x) << '\n';
	return 0;
}