#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<long double>> a (n + 1, vector<long double> (n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if (n == 1) {
		cout << 1.0 << '\n';
		return 0;
	}
	vector<vector<long double>> dp (n + 1, vector<long double> (m + 1, 0.0));
	for (int i = 1; i <= n; i++) {
		dp[i][1] = a[1][i];
	}
	for (int step = 2; step <= m; step++) {
		for (int post = 1; post <= n; post++) {
			// dp[post][step] = dp[post][step - 1] * a[]
			for (int post1 = 1; post1 <= n; post1++) {
				dp[post][step] += dp[post1][step - 1] * a[post1][post];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << fixed << setprecision(4) << dp[i][m] << '\n';
	}
	return 0;
}
