#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	const int maxn = 1001;
	vector<vector<int64_t>> a (maxn, vector<int64_t>(maxn));
	vector<vector<int64_t>> down (maxn, vector<int64_t> (maxn));
	vector<vector<int64_t>> right (maxn, vector<int64_t> (maxn));
	a[1][1] = 1;
	down[1][1] = 1;
	right[1][1] = 1;
	for (int i = 2; i < maxn; i++) {
		a[1][i] = a[1][i - 1] + i - 1;
		down[1][i] = a[1][i];
		right[1][i] = right[1][i - 1] + a[1][i];
	}
	for (int i = 2; i < maxn; i++) {
		int64_t add = i;
		for (int j = 1; j < maxn; j++) {
			a[i][j] = a[i - 1][j] + add;
			down[i][j] = down[i - 1][j] + a[i][j];
			right[i][j] = right[i][j - 1] + a[i][j];
			add += 1;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << down[x2][y1] - down[x1 - 1][y1] + right[x2][y2] - right[x2][y1 - 1] - a[x2][y1] << '\n';
	}
	return 0;
}
