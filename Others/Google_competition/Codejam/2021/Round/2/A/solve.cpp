#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n;
	cin >> t >> n;
	while (t--) {
		auto ask = [] (const int l, const int r) -> int {
			assert (l < r);
			cout << "M " << l << " " << r << endl;
			int x;
			cin >> x;
			if (x == -1) exit(0);
			return x;
		};
		auto tell = [] (const int l, const int r) {
			if (l == r) return;
			assert (l < r);
			cout << "S " << l << " " << r << endl;
			int x;
			cin >> x;
			if (x == -1) exit(0);
		};
		auto ceil = [] (const int a, const int b) -> int {
			return	a / b + (a % b != 0);
		};
		int coins = 0;
		for (int i = 1; i < n; i++) {
			int idx = ask (i, n);
			coins += ceil (1e8, n - i + 1);
			tell (i, idx);
		}
		assert (coins <= (int) 6e8);
		cout << "D" << endl;
		int x;
		cin >> x;
		if (x == -1) exit(0);
	}
	return 0;
}
