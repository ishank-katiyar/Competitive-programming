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
		int n, x, y, k;
		cin >> n >> x >> y >> k;
		vector<int> a (n);
		map <int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		int cnt = y - x + 1;
		int uni = 0, total = 0;
		for (auto& i: mp) {
			if (x <= i.first  && i.first <= y) {
				uni += 1, total += i.second;
			}
		}
		assert (total >= uni);
		int change = n - int(mp.size());
		cout << int(mp.size()) + min (min (cnt - uni, change), k) << '\n';
	}
	return 0;
}
