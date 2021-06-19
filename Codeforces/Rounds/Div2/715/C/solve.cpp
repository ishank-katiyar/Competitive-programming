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
	int n;
	cin >> n;
	vector<int64_t> a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort (a.begin(), a.end());
	vector<vector<int64_t>> dp (n, vector<int64_t> (n));
	for (int j = 0; j < n; j++) {
		for (int i = j - 1; i >= 0; i--) {
			dp[i][j] = a[j] - a[i] + min (dp[i + 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[0][n - 1] << '\n';
	return 0;
}
