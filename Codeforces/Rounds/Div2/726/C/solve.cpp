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
		vector<int> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort (a.begin(), a.end());
		if (n == 2) {
			cout << a[0] << ' ' << a[1] << '\n';
			continue;
		}
		int diff = INT_MAX;
		int idx = -1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1] - a[i] <= diff) {
				diff = a[i + 1] - a[i];
				idx = i;
			}
		}
		assert (idx != -1);
		for (int i = idx + 1; i < n; i++) {
			cout << a[i] << ' ';
		}
		for (int i = 0; i <= idx; i++) {
			cout << a[i] << " \n"[i == idx];
		}
	}
	return 0;
}
