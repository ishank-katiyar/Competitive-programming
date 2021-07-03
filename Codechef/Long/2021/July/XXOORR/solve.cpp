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
		int n, k;
		cin >> n >> k;
		vector<int64_t> a (n);
		vector<int> bit (40);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < 40; j++) {
				bit[j] += ((a[i] >> j) & 1);
			}
		}
		int ans = 0;
		for (int i = 0; i < 40; i++) {
			ans += (bit[i] + k - 1) / k;
		}
		cout << ans << '\n';
	}
	return 0;
}
