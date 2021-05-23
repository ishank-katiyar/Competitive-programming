#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int64_t n;
		cin >> n;
		vector<pair<int64_t, int64_t>> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i + 1;
		}
		map<int64_t, int64_t> mp;
		int64_t ans = 0;
		for (int i = 0; i < n; i++) {
			if (mp.count (a[i].first)) {
				ans += (n - a[i].second + 1) * mp[a[i].first];
			}
			mp[a[i].first] += a[i].second;
		}
		cout << ans << '\n';
	}
	return 0;
}
