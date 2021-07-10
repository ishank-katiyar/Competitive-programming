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
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> k >> n >> m;
		vector<int> a (n), b (m);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		reverse (a.begin(), a.end());
		reverse (b.begin(), b.end());
		vector<int> ans;
		while (a.empty() == false || b.empty() == false) {
			if (a.empty() == false && a.back() <= k) {
				ans.push_back (a.back());
				k += (a.back() == 0);
				a.pop_back();
			} else if (b.empty() == false && b.back() <= k) {
				ans.push_back (b.back());
				k += (b.back() == 0);
				b.pop_back();
			} else {
				break;
			}
		}
		if (int(ans.size()) != n + m) {
			cout << -1 << '\n';
			continue;
		}
		for (auto& i: ans) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}
