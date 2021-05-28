#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	const int x = 10000;
	int n = rnd (1, x), h = rnd (1, n), b = 1, e = n;
	cout << n << " " << h << " " << b << " " << e << '\n';
	for (int i = 0; i < n; i++) {
		cout << rnd (1, x) << " \n"[i == n - 1];
	}
	return 0;
}