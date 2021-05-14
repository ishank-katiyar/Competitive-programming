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
		map <int, int64_t> mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			x -= i + 1;
			mp[x]++;
		}
		int64_t ans = 0;
		for (auto& i: mp) {
			ans += (i.second * (i.second - 1)) / 2;
		}
		cout << ans << '\n';
	}
	return 0;	
}
