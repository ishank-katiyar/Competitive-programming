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

template <typename T, typename F = function <T (const T&, const T&)>>
class DisjointSparseTable {
protected:
	int k; // n = 2 ^ k;
	vector<vector<T>> dst;
	F func;
public:
	DisjointSparseTable (vector<T> a, const F& f) : func(f) {
		assert (a.empty() == false);
		k = 32 - __builtin_clz (static_cast <int> (a.size()));
		int n = 1 << k;
		a.resize(n);
		dst.assign (k, vector<T> (n));
		build (a);
	}

	void build (const vector<T>& a) {
		const int n = a.size();
		assert ((n & (n - 1)) == 0);
		assert ((1 << k) == n);
		for (int height = 0; height < k; height++) {
			for (int node = 0; node < (1 << height); node++) {
				int L = node * (n >> height);
				int R = L + (n >> height);
				int M = (L + R) / 2;
				dst[height][M] = a[M];
				for (int idx = M + 1; idx < R; idx++) {
					dst[height][idx] = func (dst[height][idx - 1], a[idx]);
				}
				assert (M > 0);
				dst[height][M - 1] = a[M - 1]; // might overflow here
				for (int idx = M - 2; idx >= L; idx--) {
					dst[height][idx] = func (dst[height][idx + 1], a[idx]);
				}
			}
		}
	}
};

template <typename T, typename F = function <T (const T&, const T&)>>
class RangeQuery : public DisjointSparseTable <T, F> {
	using DisjointSparseTable<T, F>::dst;
	using DisjointSparseTable<T, F>::k;
	using DisjointSparseTable<T, F>::func;
public:
	RangeQuery (vector<T> a, const F& f) : DisjointSparseTable<T, F> (a, f) {}
	T get (const int& L, const int& R) {
		if (L == R) { return dst.back()[L]; }
		assert (L < R);
		const int height = k - (31 - __builtin_clz (L ^ R)) - 1;
		return func (dst[height][L], dst[height][R]);
	}
};

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		vector<int> A (N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		auto f = [] (const vector<int> a, int k) -> bool {
			int n = int(a.size());
			RangeQuery rmq (a, [] (int x, int y) -> int { return __gcd (x, y); });
			vector<int> ans (n);
			for (int i = 0; i < n; i++) {
				ans[i] = rmq.get (i, min (i + k - 1, n - 1));
				if (i + k - 1 >= n) {
					ans[i] = __gcd (ans[i], rmq.get (0, (i + k - 1) - n));
				}
			}
			return count (ans.begin(), ans.end(), ans.front()) == n;
		};

		int low = 1, high = N;
		while (low < high) {
			int mid = (low + high) / 2;
			if (f (A, mid) == false) low = mid + 1;
			else high = mid;
		}

		cout << low - 1 << '\n';
	}
	return 0;
}
