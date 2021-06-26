#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = rnd <int> (1 << 18, 1 << 18);
	// while (n--) cout << rnd(1, 9);
	// cout << '\n';
	// n = rnd <int> (1 << 10, 1 << 10);
	// while (n--) cout << rnd(1, 9);
	// cout << '\n';
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		cout << rnd <int> (1, 1e9) << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << rnd <int> (1, 1e9) << ' ';
	}
	cout << '\n';
	return 0;
}