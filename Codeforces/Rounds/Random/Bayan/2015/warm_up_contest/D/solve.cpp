#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

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
class RangeQuery : public SparseTable <T, F> {
	using U = SparseTable<T, F>;
public:
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
	int n;
	cin >> n;
	vector<int> a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	RangeQuery rq (a, [] (int x, int y) -> int { return __gcd (x, y); });
	map <int, int64_t> mp;
	for (int i = 0; i < n; i++) {
		int start = i;
		while (start < n) {
			int gd = rq.get (i, start);
			int low = start, high = n - 1;
			while (low < high) {
				int mid = (low + high) / 2;
				if (rq.get (i, mid) == gd) low = mid + 1;
				else high = mid;
			}
			if (rq.get (i, low) != gd) low--;
			assert (low >= start && rq.get (i, low) == gd);
			mp[gd] += low - start + 1;
			start = low + 1;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << mp[x] << '\n';
	}
	return 0;
}