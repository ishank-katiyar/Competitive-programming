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
	using SparseTable<T, F>::n;
	using SparseTable<T, F>::st;
	using SparseTable<T, F>::func;
public:
	RangeQuery () {}
	RangeQuery (const vector<T>& a, const F& f) : SparseTable<T, F> (a, f) {}
	T get (const int l, const int r) {
		assert (0 <= l && l <= r && r < n);
		int lg = 31 - __builtin_clz (r - l + 1);
		return func (st[lg][l], st[lg][r - (1 << lg) + 1]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}
