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
		int subtree_sum = 0;
		int people = 0;
		int good_people = 0;
		int h_index = 0;
		vector<int> adj;
	};
	int t;
	cin >> t;
	while (t--) {
		int N, m;
		cin >> N >> m;
		vector<node> a (N);
		for (int i = 0; i < N; i++) {
			cin >> a[i].people;
		}
		for (int i = 0; i < N; i++) {
			cin >> a[i].h_index;
		}
		for (int i = 1; i < N; i++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			a[x].adj.push_back (y);
			a[y].adj.push_back (x);
		}
		bool ok = true;
		y_combinator ([&] (auto self, int n, int p) -> void {
			a[n].subtree_sum = a[n].people;
			for (auto& u: a[n].adj) {
				if (u != p) {
					self (u, n);
					a[n].subtree_sum += a[u].subtree_sum;
				}
			}
			ok &= ((a[n].subtree_sum + a[n].h_index) % 2 == 0);
			a[n].good_people = (a[n].subtree_sum + a[n].h_index) / 2;
			ok &= (a[n].good_people <= a[n].subtree_sum);
			int sum = 0;
			for (auto& u: a[n].adj) {
				if (u != p) {
					sum += a[u].good_people;
				}
			}
			ok &= (a[n].good_people >= sum);
		}) (0, -1);
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
