#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	const int x = 1000;
	int n = rnd (x, x), m = rnd (x, x);
	int y = 50;
	// int a = rnd (1, min (n, 10)), b = rnd (1, min (m, 10));
	int a = y, b = y;
	cout << n << " " << m << " " << a << " " << b << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << rnd <int> (1, 1e9) << " \n"[j == m - 1];
		}
	}
	return 0;
}
