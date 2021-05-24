#include <bits/stdc++.h>

using namespace std;

class graph {
public:
	int n;
	vector<vector<int>> adj;
	vector<int> degree;
	vector<pair<int, int>> edge;
	vector<int> depth;
	vector<bool> covered;
	vector<vector<int64_t>> dp;
	vector<pair<int64_t, int64_t>> value;
	graph (int N): n (N), adj (vector<vector<int>> (n)), degree (vector<int> (n)), depth (vector<int> (n)), covered (vector<bool> (n, false)), dp (vector<vector<int64_t>> (n, vector<int64_t> (2))), value (vector<pair<int64_t, int64_t>> (n)) {}
	void add (int X, int Y) {
		degree[X]++, degree[Y]++;
		edge.emplace_back(X, Y);
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
	void dfs (int N) {
		if (covered[N] == true) return;
		covered[N] = true;
		dp[N][0] = dp[N][1] = 0;
		for (int i: adj[N]) {
			if (covered[i] == false) {
				dfs(i);
				dp[N][0] += max (dp[i][0] + abs (value[N].first - value[i].first), dp[i][1] + abs (value[N].first - value[i].second));
				dp[N][1] += max (dp[i][0] + abs (value[N].second - value[i].first), dp[i][1] + abs (value[N].second - value[i].second));
			} 
		}
	}
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		graph g (n + 1);
		for (int i = 0; i < n; i++) {
			int l, r;
			cin >> l >> r;
			g.value[i + 1] = make_pair (l, r);
		}
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			g.add (x, y);
		}
		g.dfs (1);
		cout << max (g.dp[1][0], g.dp[1][1]) << '\n';
	}
	return 0;
}