#include <bits/stdc++.h>

using namespace std;

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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}
