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
		auto flip = [] (char& ch) -> char {
			if (ch == '1') return '0';
			return '1';
		};
		int n, m;
		cin >> n >> m;
		char ch = '1';
		string ss = "";
		int M = m;
		while (M--) {
			ss.push_back (ch);
			ch = flip(ch);
		}
		// vector<string> a (n, string(m, '0'));
		for (int i = 0; i < n; i++) {
			if (i == 0 || i == n - 1) cout << ss << '\n';
			else if (i % 2 == 0 && i > 0 && i + 2 < n) {
				cout << '1' << string (m - 2, '0') << '1' << '\n';	
			}
			else cout << string (m, '0') << '\n';
		}
		// for (int i = 0; i < m; i++) {
		// 	a[0][i] = ch;
		// 	ch = flip (ch);
		// }
		// ch = a[0][0];
		// for (int i = 0; i < n; i++) {
		// 	a[i][0] = ch;
		// 	ch = flip (ch);
		// }
		// ch = a[n - 1][0];
		// for (int j = 0; j < m; j++) {
		// 	a[n - 1][j] = ch;
		// 	ch = flip (ch);
		// }
		// ch = a[0][m - 1];
		// for (int i = 0; i < n; i++) {
		// 	a[i][m - 1] = ch;
		// 	ch = flip (ch);
		// }
		// if (a[n - 1][m - 1] == '1' && a[n - 2][m - 1] == '1') a[n - 1][m - 1] = '0';
		// for (auto& i: a) {
		// 	cout << i << '\n';
		// }
	}
	return 0;
}
