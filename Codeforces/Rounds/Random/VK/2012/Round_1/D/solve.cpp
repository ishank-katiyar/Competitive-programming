#include <bits/stdc++.h>

using namespace std;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};

template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

} // namespace std

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	struct node {
		int depth = -1;
		vector<int> adj;
	};
	int n, k;
	cin >> n >> k;
	vector<node> gr (n);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gr[x].adj.push_back(y);
		gr[y].adj.push_back(x);
	}
	y_combinator([&] (auto self, int n, int p) -> void {
		gr[n].depth = gr[p].depth + 1;
		for (auto& i: gr[n].adj) {
			if (i != p) self (i, n);
		}
	}) (0, 0);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[gr[i].depth]++;
	}
	int64_t ans = 0;
	for (auto& i: gr[0].adj) {
		map<int, int> cur;
		y_combinator ([&] (auto self, int n, int p) -> void {
			// cur[]
		}) (i, 0);
	}
	return 0;
}
