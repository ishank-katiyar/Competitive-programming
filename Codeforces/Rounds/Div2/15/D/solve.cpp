#include <bits/stdc++.h>

using namespace std;

template<typename T, typename F = function <T (const T &, const T &)>>
class SparseTable2d {
protected:
	int n, m;
	vector<vector<vector<vector<T>>>> st;
	F func;
public:
	SparseTable2d () {}
	SparseTable2d (const vector<vector<T>>& a, const F& f): n (static_cast<int> (a.size())), func (f) {
		assert (n > 0);
		m = a.front().size();
		int k1 = 32 - __builtin_clz (n), k2 = 32 - __builtin_clz (m);
		st.assign (k1, vector<vector<vector<T>>> (k2, vector<vector<T>> (n + 1, vector<T> (m + 1, 0))));
		build (a);
	}

	void build (const vector<vector<T>> & a) {
		int k1 = 32 - __builtin_clz (n), k2 = 32 - __builtin_clz (m);
		st[0][0] = a;
		for (int k = 0; k < n; k++) {
			for (int j = 1; j < k2; j++) {
				for (int l = 0; l + (1 << j) <= m; l++) {
					st[0][j][k][l] = func (st[0][j - 1][k][l], st[0][j - 1][k][l + (1 << (j - 1))]);
				}
			}
		}
		for (int i = 1; i < k1; i++) {
			for (int j = 0; j < k2; j++) {
				for (int k = 0; k + (1 << i) <= n; k++) {
					for (int l = 0; l + (1 << j) <= m; l++) {
						st[i][j][k][l] = func (st[i - 1][j][k][l], st[i - 1][j][k + (1 << (i - 1))][l]);
					}
				}
			}
		}
	}
};

template<typename T, typename F = function <T (const T &, const T &)>>
class RangeQuery2d : public SparseTable2d <T, F> {
	using SparseTable2d<T, F>::n;
	using SparseTable2d<T, F>::m;
	using SparseTable2d<T, F>::st;
	using SparseTable2d<T, F>::func;
public:
	RangeQuery2d () {}
	RangeQuery2d (const vector<vector<T>> & a, const F& f) : SparseTable2d <T, F> (a, f) {}
	T get (int x1, int y1, int x2, int y2) {
		assert ((0 <= x1 && x1 <= x2 && x2 < n) && (0 <= y1 && y1 <= y2 && y2 < m));
		int lg1 = 31 - __builtin_clz (x2 - x1 + 1), lg2 = 31 - __builtin_clz (y2 - y1 + 1);
		return func (st[lg1][lg2][x1][y1], func (st[lg1][lg2][x1][y2 - (1 << lg2) + 1], func (st[lg1][lg2][x2 - (1 << lg1) + 1][y1], st[lg1][lg2][x2 - (1 << lg1) + 1][y2 - (1 << lg2) + 1])));
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int64_t>> h (n, vector<int64_t> (m)), dp (n, vector<int64_t> (m, 0));
	for (int i = 0; i < n; i++) {
		int64_t sum = 0;
		for (int j = 0; j < m; j++) {
			cin >> h[i][j];
			sum += h[i][j];
			if (i > 0) dp[i][j] += dp[i - 1][j];
			dp[i][j] += sum;
		}
	}
	auto range_sum = [&] (int x1, int y1, int x2, int y2) -> int64_t {
		assert (0 <= x1 && x1 <= x2 && x2 < n && 0 <= y1 && y1 <= y2 && y2 < m);
		int64_t res = dp[x2][y2];
		if (x1 > 0) res -= dp[x1 - 1][y2];
		if (y1 > 0) res -= dp[x2][y1 - 1];
		if (x1 > 0 && y1 > 0) res += dp[x1 - 1][y1 - 1];
		return res;
	};
	RangeQuery2d <int64_t> rmq (h, [](int64_t x, int64_t y) -> int64_t { return min (x, y); });
	set<pair<int64_t, pair<int, int>>> s;
	for (int i = 0; i < n - a + 1; i++) {
		for (int j = 0; j < m - b + 1; j++) {
			s.insert (make_pair (range_sum (i, j, i + a - 1, j + b - 1) - a * b * rmq.get (i, j, i + a - 1, j + b - 1), make_pair (i, j)));
		}
	}
	vector<vector<bool>> used (n, vector<bool> (m, false));
	vector<tuple<int, int, int64_t>> ans;
	while (s.empty() == false) {
		auto [cur_sum, p] = *s.begin();
		bool usable = true;
		for (int i = p.first; i < p.first + a; i++) {
			for (int j = p.second; j < p.second + b; j++) {
				usable &= used[i][j] == false;
			}
		}
		if (usable) {
			ans.push_back(make_tuple (p.first, p.second, cur_sum));
			for (int i = p.first; i < p.first + a; i++) {
				for (int j = p.second; j < p.second + b; j++) {
					if (i + a - 1 < n && j + b - 1 < m) {
						auto pp = make_pair (range_sum (i, j, i + a - 1, j + b - 1) - a * b * rmq.get (i, j, i + a - 1, j + b - 1), make_pair (i, j));
						assert (s.find (pp) != s.end ());
						s.erase (pp);
					}
					used[i][j] = true;
				}
			}
		}
		s.erase (s.begin());
	}
	cout << ans.size() << '\n';
	for (auto& i: ans) cout << get<0> (i) + 1 << ' ' << get<1> (i) + 1 << ' ' << get<2> (i) << '\n';
	return 0;
}
