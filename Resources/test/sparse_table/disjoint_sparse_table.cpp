#include <bits/stdc++.h>

using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* ch) { return string(ch); }
string to_string(char ch) { return (string)"'" + ch + (string)"'"; }
string to_string(bool b) { return (b ? "true" : "false"); }
template<class A, class B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<class A>
string to_string(A a) {
	string res = "{";
	bool first = true;
	for(const auto& x: a) { if(first == false) res += ", "; first = false, res += to_string(x); }
	res += "}";
	return res;
}

void debug() {cerr << "]\n";}
template<class H, class... T> void debug(H head, T... tail) 	{ cerr << to_string(head) << " "; debug(tail...); }
#ifdef LOCAL
	#define debug(...) cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else
	#define debug(...)
#endif

template <typename T, typename F = function <T (const T&, const T&)>>
class DisjointSparseTable {
protected:
	int k;
	vector<vector<T>> dst;
	F func;
public:
	DisjointSparseTable (vector<T> a, const F& f) : func(f) {
		k = 32 - __builtin_clz (static_cast <int> (a.size()));
		const int n = 1 << k;
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
	int n;
	cin >> n;
	vector<int64_t> a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	RangeQuery rq (a, [](int64_t x, int64_t y) -> int64_t {return x + y;});
	for (int i = 0; i < n; i++) {
		int64_t sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			int64_t res = rq.get (i, j);
			debug (i, j, res, sum);
			assert (res == sum);
		}
	}
	return 0;
}
