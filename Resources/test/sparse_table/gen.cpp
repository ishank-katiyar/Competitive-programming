#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	const int xx = 10000;
	int n = rnd (xx, xx);
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		cout << rnd (xx, xx) << " \n"[i == n - 1];
	}
	return 0;
}