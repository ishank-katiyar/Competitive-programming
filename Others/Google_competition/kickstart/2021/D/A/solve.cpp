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
	int TT;
	cin >> TT;
	for (int ttt = 1; ttt <= TT; ttt++) {
		int a1, a2, a3, a4, a6, a7, a8, a9;
		cin >> a1 >> a2 >> a3 >> a4 >> a6 >> a7 >> a8 >> a9;
		int ans = 0;
		ans += ((a2 - a1) == (a3 - a2));
		ans += ((a8 - a7) == (a9 - a8));
		ans += ((a4 - a1) == (a7 - a4));
		ans += ((a6 - a3) == (a9 - a6));
		map<int, int> mp;
		if ((a2 + a8) % 2 == 0) {
			mp[(a2 + a8) / 2]++;
		}
		if ((a4 + a6) % 2 == 0) {
			mp[(a4 + a6) / 2]++;
		}
		if ((a1 + a9) % 2 == 0) {
			mp[(a1 + a9) / 2]++;
		}
		if ((a3 + a7) % 2 == 0) {
			mp[(a3 + a7) / 2]++;
		}
		int ans1 = 0;
		for (auto& i: mp) {
			ans1 = max (ans1, i.second);
		}
		cout << "Case #" << ttt << ": " << ans + ans1 << '\n';
	}
	return 0;
}
