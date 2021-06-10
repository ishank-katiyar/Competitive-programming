#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> c (n);
	vector<map<int, int>> node (n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		node[i][x] += 1;
	}
	vector<int> parent (n), size (n, 1);
	iota (parent.begin(), parent.end(), 0);
	function<int(int)> rep = [&] (int A) -> int {
		return parent[A] == A ? A : parent[A] = rep(parent[A]);
	};
	auto unite = [&] (int A, int B) {
		int ra = rep (A), rb = rep (B);
		if (ra != rb) {
			if (size[ra] > size[rb]) swap (ra, rb);
			parent[ra] = rb;
			for (auto& i: node[ra]) {
				node[rb][i.first] += i.second;
			}
			size[rb] += size[ra];
		}
	};
	while (q--) {
		int type, a, b;
		cin >> type >> a >> b;
		a--, b--;
		if (type == 1) {
			unite (a, b);
		} else {
			cout << node[rep(a)][b + 1] << '\n';
		}
	}
	return 0;
}
