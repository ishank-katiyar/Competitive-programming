#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = rnd ((int) 1, (int) 1e5);
	while (n--) cout << rnd(1, 9);
	cout << '\n';
	n = rnd ((int) 1, (int) 1e5);
	while (n--) cout << rnd(1, 9);
	cout << '\n';
	return 0;
}