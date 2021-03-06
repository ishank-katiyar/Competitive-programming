#include <bits/stdc++.h>

using namespace std;

template <typename T, typename F = function <T (const T &, const T &)>>
class SparseTable {
protected:
	int n;
	vector<vector<T>> st;
	F func;
public:
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
class RMQ : public SparseTable <T, F> {
	using Type = SparseTable<T, F>;
public:
	RMQ (const vector<T>& a, const F& f) : SparseTable <T, F> (a, f) {}
	T get (const int l, const int r) {
		assert (0 <= l && l <= r && r < Type::n);
		int lg = 31 - __builtin_clz (r - l + 1);
		return Type::func (Type::st[lg][l], Type::st[lg][r - (1 << lg) + 1]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a (n), diff (n - 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) diff[i - 1] = a[i] - a[i - 1];
	}
	diff.push_back(INT_MAX);
	RMQ <int> rmq (diff, [] (int x, int y) -> int { return max (x, y); });
	int q;
	cin >> q;
	while (q--) {
		int t, d;
		cin >> t >> d;
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		int r = upper_bound (a.begin(), a.end(), t) - a.begin(); 
		int low = 0, high = r - 1;
		while (low < high) {
			int mid = (low + high) / 2;
			if (rmq.get (mid, r - 2) <= d) high = mid;
			else low = mid + 1;
		}
		cout << low + 1 << '\n';
	}
	return 0;
}
