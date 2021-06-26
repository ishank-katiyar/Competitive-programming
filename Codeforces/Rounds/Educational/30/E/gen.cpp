#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	const int x = 5;
	int n = rnd (3, x);
	cout << n << '\n';
	// const int diff = 3;
	// int start = rnd (1, 1 + diff);
	vector<int> a (n);
	// a[0] = start;
	// int prev_dd = 1;
	for (int i = 0; i < n; i++) {
		// a[i] = rnd (a[i - 1] + prev_dd, a[i - 1] + prev_dd + diff);
		// prev_dd = a[i] - a[i - 1];
		a[i] = rnd (1, 5 * x);
	}
	// random_shuffle (a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
	}
	return 0;
}