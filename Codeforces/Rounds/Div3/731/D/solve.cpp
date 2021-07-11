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
		int n;
		cin >> n;
		vector<int64_t> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int64_t> ans;
		ans.push_back (0);
		for (int i = 1; i < n; i++) {
			int64_t y = 0;
			for (int j = 0; j < 40; j++) {
				if (((ans.back() ^ a[i - 1]) >> j) & 1) {
					if (!((a[i] >> j) & 1)) {
						y += (int64_t(1) << j);
					}
				}
			}
			ans.push_back (y);
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}
