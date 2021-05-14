#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> a (6), b (6);
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 6; i++) {
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			ans += (a[i] > b[j]);
		}
	}
	int gd = __gcd (ans, 36);
	cout << ans / gd << '/' << 36 / gd << '\n';
	return 0;
}
