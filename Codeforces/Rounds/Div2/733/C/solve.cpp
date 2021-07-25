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
		vector<int> b (n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort (a.rbegin(), a.rend());
		sort (b.rbegin(), b.rend());
		vector<int64_t> prea (n);
		prea[0] = a[0];
		for (int i = 1; i < n; i++) {
			prea[i] = prea[i - 1] + a[i];
		}
		vector<int64_t> preb (n);
		preb[0] = b[0];
		for (int i = 1; i < n; i++) {
			preb[i] = preb[i - 1] + b[i];
		}

		auto f = [&] (int64_t M) -> bool {
			int64_t xx = (n + M) - ((n + M) / 4);
			int64_t A = min (M, xx) * 100;
			int64_t rem = max (xx - M, int64_t(0));
			if (rem > 0) {
				assert (rem <= n);
				A += prea [rem - 1];
			}
			int64_t B = preb [min (xx, int64_t(n)) - 1];
			return A >= B;
		};

		int64_t low = 0, high = 1e15;

		while (low < high) {
			int mid = (low + high) / 2;
			if (f (mid)) {
				high = mid;
			}	else {
				low = mid + 1;
			}
		}
		cout << low << '\n';
	}
	return 0;
}
