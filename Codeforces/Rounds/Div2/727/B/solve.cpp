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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<vector<int>> dp (26, vector<int> (n));	
	dp[int(s.front() - 'a')][0] = 1;
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] += dp[i][j - 1] + (int(s[j] - 'a') == i);
		}
	}
	auto f = [&] (int x, int l, int r) -> int {
		if (l == 0) return dp[x][r];
		return dp[x][r] - dp[x][l - 1];
	};
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			ans += (i + 1) * f (i, l, r);
		}
		cout << ans << '\n';
	}
	return 0;
}
