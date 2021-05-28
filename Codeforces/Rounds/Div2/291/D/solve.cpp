#include <bits/stdc++.h>

using namespace std;

template <typename T, typename F = function <T (const T &, const T &)>>
class SparseTable {
protected:
	int n;
	vector<vector<T>> st;
	F func;
public:
	SparseTable () {}
	SparseTable (const vector<T>& a, const F& f) : n (static_cast<int>(a.size())), func (f) {
		assert (n > 0);
		int k = 32 - __builtin_clz (n);
		st.assign (k, vector<T> (n + 1));
		build (a);
	}

	void build (const vector<T>& a) {
		int k = 32 - __builtin_clz (n);
		st[0] = a;
		for (int j = 1; j < k; j++) {
			for (int i = 0; i + (1 << j) <= n; i++) {
				st[j][i] = func (st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
};

template <typename T, typename F = function <T (const T &, const T &)>>
class RangeQuery : public SparseTable <T, F> {
	using U = SparseTable<T, F>;
public:
	RangeQuery () {}
	RangeQuery (const vector<T>& a, const F& f) : SparseTable <T, F> (a, f) {}
	T get (const int l, const int r) {
		assert (0 <= l && l <= r && r < U::n);
		int lg = 31 - __builtin_clz (r - l + 1);
		return U::func (U::st[lg][l], U::st[lg][r - (1 << lg) + 1]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a (m, vector<int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[j][i];
		}
	}
	vector<RangeQuery<int>> rmq(m);
	for (int i = 0; i < m; i++) {
		rmq[i] = RangeQuery<int> (a[i], [] (int x, int y) -> int { return max (x, y); });
	}
	auto ff = [&] (const int l, const int r) -> vector<int> {
		vector<int> res;
		for (int i = 0; i < m; i++) {
			res.push_back(rmq[i].get (l, r));
		}
		return res;
	};
	int ans = 0;
	vector<int> ans_ (m, 0);
	int j = 0;
	for (int i = 0; i < n; i++) {
		j = max (i, j);
		vector<int> tmp = ff (i, min (j, n - 1));
		while (j < n && accumulate(tmp.begin(), tmp.end(), 0) <= k) j++, tmp = ff (i, min (j, n - 1));
		assert (j >= i);
		if (j - i > ans) {
			ans = j - i;
			ans_ = ff (i, j - 1);
		}
	}
	for (auto& i: ans_) cout << i << ' ';
	cout << '\n';
	return 0;
}
