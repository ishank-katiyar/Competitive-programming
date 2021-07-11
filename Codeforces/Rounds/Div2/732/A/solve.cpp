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
		vector<pair<int, int>> a (n);
		int sum1 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			sum1 += a[i].first;
			a[i].second = i;
		}
		int sum2 = 0;
		vector<int> b (n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			sum2 += b[i];
		}
		if (sum1 != sum2) {
			cout << -1 << '\n';
			continue;
		}
		// sort (a.begin(), a.end());
		// sort (b.begin(), b.end());
		// vector<pair<int, int>> ans;
		// int j = n - 1;
		// while (j >= 0 && a[j].first == b[j]) j--;
		// for (int i = 0; i < j; i++) {
		// 	while (j >= 0 && a[j].first == b[j]) j--;
		// 	while (a[i].first < b[i]) {
		// 		ans.push_back (make_pair (a[i].second, a[j].second));
		// 		a[i].first += 1;
		// 		a[j].first -= 1;
		// 	}
		// }
		// cout << ans.size() << '\n';
		// for (auto& i: ans) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
		vector<int> fi, se;
		for (int i = 0; i < n; i++) {
			while (a[i].first < b[i]) {
				fi.push_back (i);
				a[i].first += 1;
			} 
			while (a[i].first > b[i]) {
				se.push_back (i);
				a[i].first -= 1;
			}
		}
		assert (int(fi.size()) == int(se.size()));
		cout << int(fi.size()) << '\n';
		for (int i = 0; i < int(fi.size()); i++) {
			cout << se[i] + 1 << ' ' << fi[i] + 1 << '\n';
		}
	}
	return 0;
}
