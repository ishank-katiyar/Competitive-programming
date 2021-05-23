#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int k;
		cin >> k;
		vector<int64_t> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<bool> used (n, false);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (used[i]) continue;
			map<int, int> mp;
			int j = i;
			while (j < n) {
				used[j] = true;
				mp[a[j]]++;
				j += k;
			}
			int total = 0, mx = 0;
			for (auto& I: mp) {
				total += I.second;
				mx = max (mx, I.second);
			}
			ans += total - mx;
		}
		cout << ans << '\n';
	}	
	return 0;
}
