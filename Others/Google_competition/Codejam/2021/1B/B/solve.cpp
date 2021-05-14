#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	for (int ttt = 1; ttt <= tt; ttt++) {
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> u (n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> u[i];
		}

		auto f = [&] (const int X) -> bool {
			map<int, int> aa;
			aa[X] = 1;
			vector<int> cur_u (u);
			while (aa.empty() == false) {
				for (auto& i: aa) {
					if (i.first <= n && i.first >= 1) {
						int mn = min (i.second, cur_u[i.first]);
						i.second -= mn;
						cur_u[i.first] -= mn;
					}
				}
				map<int, int> new_aa;
				for (auto& i: aa) {
					if (i.first - a >= 1) {
						new_aa[i.first - a] += i.second;
					}
					if (i.first - b >= 1) {
						new_aa[i.first - b] += i.second;
					}
				}
				aa = new_aa;
			}
			bool ok = true;
			for (int i = 1; i <= n; i++) {
				ok &= (cur_u[i] == 0);
			}
			return ok;
		};

		const int maxans = 500;

		int ans = 0;

		for (int i = 1; i <= maxans; i++) {
			if (f (i)) {
				ans = i;
				break;
			}
		}

		cout << "Case #" << ttt << ": ";

		if (ans == 0) {
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		cout << ans << '\n';
	}
	return 0;
}