#include <bits/stdc++.h>

using namespace std;

struct node {
	vector<int> adj;
	int subtree_nodes = 0;
};

int dfs (vector<node> &gr, int n, int p) {
	int cur = 0;
	for (auto v: gr[n].adj) {
		if (v != p) {
			cur += dfs (gr, v, n);
		}
	}
	gr[n].subtree_nodes = cur + 1;
	return gr[n].subtree_nodes;
}

void dfs1 (const vector<node> &gr, int n, int p, vector<int64_t> &all_paths, map<pair<int, int>, int64_t> &weights) {
	for (int v: gr[n].adj) {
		if (v != p) {
			auto pp = make_pair(min (v, n), max(v, n));
			all_paths.push_back ((1ll * gr[v].subtree_nodes * (int(gr.size()) - gr[v].subtree_nodes)) * weights[pp]);
			dfs1 (gr, v, n, all_paths, weights);
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;

	assert (1 <= T && T <= 5);

	while (T--) {
		int n;
		cin >> n;
		assert (1 <= n && n <= int(1e5));
		vector<node> gr (n);
		map<pair<int, int>, int64_t> weights;
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			assert (1 <= x && x <= n && 1 <= y && y <= n);
			x--, y--;
			gr[x].adj.push_back(y);
			gr[y].adj.push_back(x);
			int wei;
			cin >> wei;
			assert (1 <= wei && wei <= int(1e3));
			weights[make_pair(min (x, y), max(x, y))] = wei;
		}
		dfs (gr, 0, -1);
		vector<int64_t> b;
		dfs1 (gr, 0, -1, b, weights);
		assert (int(b.size()) == n - 1);
		sort (b.begin(), b.end());
		int64_t ans = accumulate(b.begin(), b.end(), 0ll);
		cout << ans << ' ';
		for (int i = 0; i < n - 1; i++) {
			ans -= 2 * b[i];
			cout << ans << " ";
		}
		cout << '\n';
	}

	return 0;
}
