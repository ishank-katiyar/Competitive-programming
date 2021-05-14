#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<bool>> used (n, vector<bool> (m, false));
		function<int(int, int)> dfs = [&] (int r, int c) -> int {
			if (used[r][c] || a[r][c] == '0') {
				return 0;
			}
			used[r][c] = true;
			int ret = 0;
			if (r - 1 >= 0) {
				ret += dfs (r - 1, c);
			}
			if (r + 1 < n) {
				ret += dfs (r + 1, c);
			}
			if (c - 1 >= 0) {
				ret += dfs (r, c - 1);
			}
			if (c + 1 < m) {
				ret += dfs (r, c + 1);
			}
			return 1 + ret;
		};
		vector<int> land;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (used[i][j] == false) {
					land.push_back(dfs (i, j));
				}
			} 
		}
		sort (land.rbegin(), land.rend());
		int ans = 0;
		for (int i = 1; i < (int)land.size(); i += 2) {
			ans += land[i];
		}
		cout << ans << '\n';
	}
	return 0;
}