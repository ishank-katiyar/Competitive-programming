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

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
 int n = rnd(9, 9);
	cout << n << '\n';
	while (n--) cout << rnd(0, 2);
	cout << '\n';
	return 0;
}

