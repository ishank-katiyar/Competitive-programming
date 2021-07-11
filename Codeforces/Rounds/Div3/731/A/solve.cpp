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
		int xa, ya, xb, yb, xf, yf;
		cin >> xa >> ya >> xb >> yb >> xf >> yf;
		if (xa != xb && ya != yb) {
			cout << abs (xa - xb) + abs (ya - yb) << '\n';
		}	else if (xa == xb && xa == xf && min (ya, yb) <= yf && yf <= max (ya, yb)) {
			cout << abs (ya - yb) + 2 << '\n';
		}	else if (ya == yb && ya == yf && min (xa, xb) <= xf && xf <= max (xa, xb)) {
			cout << abs (xa - xb) + 2 << '\n';
		}	else {
			cout << abs (xa - xb) + abs (ya - yb) << '\n';
		}
	}
	return 0;
}
