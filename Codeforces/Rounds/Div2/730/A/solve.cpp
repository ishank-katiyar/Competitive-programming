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
		int64_t a, b;
		cin >> a >> b;
		auto dif =  abs (a - b);
		if (a == b) {
			cout << "0 0" << '\n';
			continue;
		}
		cout << dif << ' ' << min (min (a % dif, dif - (a % dif)), min (b % dif, dif - (b % dif))) << '\n';
	}
	return 0;
}
