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
		if (n == 1) {
			cout << a[0] << '\n';
			continue;
		}
		int64_t ans = 0;
		for (int i = 1; i < n - 1; i++) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				int mx = max (a[i - 1], a[i + 1]);
				ans += a[i] - mx;
				a[i] = mx;
			}
		}
		if (a[0] > a[1]) {
			ans += a[0] - a[1];
			a[0] = a[1];
		}
		if (a[n - 2] < a[n - 1]) {
			ans += a[n - 1] - a[n - 2];
			a[n - 1] = a[n - 2];
		}
		for (int i = 1; i < n; i++) {
			ans += abs (a[i] - a[i - 1]);
		}
		ans += a.back() + a.front();
		cout << ans << '\n';
	}
	return 0;
}
