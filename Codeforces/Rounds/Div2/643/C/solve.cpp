#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int64_t a, b, c, d;
	cin >> a >> b >> c >> d;
	int64_t ans = 0;
	for (int sum = a + b; sum <= b + c; sum++) {
		int64_t x1 = b - a, x2 = c - b, x3 = sum - a - b;
		if (x2 > x1) swap (x1, x2);
		int64_t cnt1 = min (min (x2 + 1, x3 + 1), x1 - (max (int64_t(0), x3 - x2)) + 1);
		int64_t cnt2 = min (max (sum - c, int64_t(0)), d - c + 1);
		ans += cnt1 * cnt2;
	}
	cout << ans << '\n';
	return 0;
}
