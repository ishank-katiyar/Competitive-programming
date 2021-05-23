#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int64_t x, y;
		cin >> x >> y;
		vector<pair<int64_t, int>> a;
		for (int i = 1; i < 64; i++) {
			int64_t a1 = (1ll << i) - 1;
			if (__int128(1) * a1 * x > __int128(y)) break;
			a.push_back (make_pair (a1 * x, i));
		}
		int ans = 0;
		int cnt = 0;
		int sz = a.size ();
		for (int i = sz - 1; i >= 0; i--) {
			if (a[i].first <= y) {
				y -= a[i].first;
				ans += a[i].second;
				cnt += 1;
			}
		}
		if (y > 0) {
			cout << -1 << '\n';
			continue;
		}
		cout << ans + cnt - 1 << '\n';
	}
	return 0;
}
