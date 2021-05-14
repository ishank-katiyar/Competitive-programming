#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int64_t sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	int q;
	cin >> q;
	const int mod = 1e9 + 7;
	while (q--) {
		sum *= 2;
		sum %= mod;
		if (sum < 0) sum += mod;
		cout << sum << '\n';
	}
	return 0;
}
