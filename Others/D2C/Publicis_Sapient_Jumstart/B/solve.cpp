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
	string s;
	cin >> s;
	assert (s.front() == 'U');
	assert (s.back() == 'D');
	int n = s.size();
	int64_t ans = 2 * n - 2;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == 'U') {
			ans += 2 * i;
			ans += n - i - 1;
		} else {
			ans += 2 * (n - i - 1);
			ans += i;
		}
	}
	cout << ans << '\n';
	return 0;
}
