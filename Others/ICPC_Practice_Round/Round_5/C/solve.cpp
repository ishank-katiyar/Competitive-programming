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
		int n, m;
		cin >> n >> m;
		vector<string> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort (a.begin(), a.end());
		int ans = m;
		for (int i = 1; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				if (a[i][j] == a[i - 1][j]) cnt += 1;
				else break;
			}
			ans += m - cnt;
		}
		cout << ans << '\n';
	}
	return 0;
}
