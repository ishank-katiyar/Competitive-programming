#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int64_t x, y, a, b;
		cin >> x >> y >> a >> b;
		if (a == b) {
			cout << min (x / a, y / a) << '\n';
			continue;
		}
		int64_t mx = (x + y) / (a + b);
		int64_t ans = 0;
		for (int64_t i = 0; i <= mx; i++) {
			for (int64_t j = 0; j <= mx; j++) {
				if (a * i + b * j <= x && b * i + a * j <= y) ans = max (ans, i + j);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
