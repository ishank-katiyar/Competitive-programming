#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int64_t L, G;
	cin >> L >> G;
	int64_t ans = 0;
	for (int i = 0; i < G; i++) {
		int64_t cur;
		int64_t x, y;
		cin >> x >> y;
		if (y) {
			cur = L - x;
		}	else {
			cur = x;
		}
		ans = max (ans, cur);
	}
	cout << ans << '\n';
	return 0;
}
