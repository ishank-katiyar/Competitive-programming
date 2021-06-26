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
	int64_t n, k, x;
	cin >> n >> k >> x;
	vector<int64_t> a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort (a.begin(), a.end());
	vector<int64_t> diff;
	for (int i = 1; i < n; i++) {
		diff.push_back (a[i] - a[i - 1] - 1);
	}
	sort (diff.begin(), diff.end());
	int cnt = n;
	for (auto& i: diff) {
		int64_t cnt1 = max (i / x, int64_t(0));
		if (k >= cnt1) k -= cnt1, cnt--;
	}
	cout << cnt << '\n';
	return 0;
}
