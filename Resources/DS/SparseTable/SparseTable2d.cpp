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
	
	return 0;
}
