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
	int n, m;
	cin >> n >> m;
	vector<int> l (m);
	for (int i = 0; i < m; i++) {
		cin >> l[i];
	}
	vector<pair<int, int>> a;
	vector<int> mx;
	bool ok = true;
	a.push_back(make_pair(1, 1 + l[0] - 1));
	mx.push_back(a.back().second);
	for (int i = 1; i < m; i++) {
		if (i + 1 + l[i] - 1 > n) {
			ok = false;
			break;
		}
		a.push_back(make_pair(i + 1, i + 1 + l[i] - 1));
		mx.push_back(max (mx.back(), a.back().second));
	}
	if (ok == false) {
		cout << -1 << '\n';
		return 0;
	}
	int last = n;
	int idx = m - 1;
	while (idx >= 0) {
		assert (last > 0);
		if (mx[idx] < last) {
			a[idx] = make_pair (last - l[idx] + 1, last);
			last = a[idx].first - 1;
		}	else {
			break;
		}
		idx--;
	}
	if (accumulate(l.begin(), l.end(), 0ll) < n) {
		cout << -1 << '\n';
	} else {
		for (int i = 0; i < m; i++) {
			cout << a[i].first << " \n"[i == m - 1];
		}
	}
	return 0;
}
