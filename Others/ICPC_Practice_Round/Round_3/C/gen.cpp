#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd() {
	return uniform_int_distribution<int> (1, (int) 1e9) (rng);
}

template<class A> 
A rnd(A x, A y) {
	return uniform_int_distribution<A> (x, y) (rng);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = rnd (1, 5);
	int m = rnd (1, 10);
	cout << n << ' ' << m << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << fixed << setprecision (3) << (long double) 1 / rnd (1, 10) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
