#warning not accepted soln

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
	RangeQuery (const vector<T>& a, const F& f) : U (a, f) {}
	T get (const int l, const int r) {
		assert (0 <= l && l <= r && r < U::n);
		int lg = 31 - __builtin_clz (r - l + 1);
		return U::func (U::st[lg][l], U::st[lg][r - (1 << lg) + 1]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		int h, b, e;
		cin >> h >> b >> e;
		b--, e--;
		assert (e >= b);
		vector<int> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		RangeQuery <int> rmq (a, [] (int x, int y) -> int { return min (x, y); });
		vector<int> ans (n);
		int idx = 0;
		while (idx < n) {
			if (idx == n - 1) {
				ans[idx] = 1;
				break;
			}
			int low = idx + 1, high = n - 1;
			while (low < high) {
				int mid = (low + high) >> 1;
				if (rmq.get (idx + 1, mid) > a[idx]) {
					low = mid + 1;
				} else {
					high = mid;
				}
			}
			if (low == n - 1 && a[low] > a[idx]) {
				int len = min (h, low - idx + 1);
				ans[idx] = len;
				idx += len;
				continue;
			}
			assert (low > idx && a[low] <= a[idx]);
			if (low > idx + 1) assert (rmq.get (idx + 1, low - 1) > a[idx]);
			int len = low - idx;
			len = min (h, len);
			ans[idx] = len;
			idx += len;
		}
		for (int i = b; i <= e; i++) {
			cout << ans[i] << " \n"[i == e];
		}
	}
	return 0;
}
