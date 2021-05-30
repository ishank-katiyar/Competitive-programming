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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a (n, vector<int> (m));
	for (auto& i: a) for (auto& j: i) cin >> j;
	vector<vector<int>> dp (n, vector<int> (m));
	dp[0][0] = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			if (a[i][j] == 0) continue;
			int x = INT_MAX;
			if (i > 0 && j > 0) x = min (x, dp[i - 1][j - 1]);
			if (i > 0) x = min (x, dp[i - 1][j]);
			if (j > 0) x = min (x, dp[i][j - 1]);
			if (i == 0 || j == 0) x = 0;
			dp[i][j] = x + 1;
		}
	}
	debug (dp);
	RangeQuery2d rmq (dp, [](int x, int y) -> int { return max (x, y); });
	int q;
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		int low = 0, high = min (n, m);
		auto f = [&] (int x) -> bool {
			if (x == 0) return true;
			assert (x > 0);
			int new_x1 = x1 + x - 1, new_y1 = y1 + x - 1;
			if (new_x1 > x2 || new_y1 > y2) return false;
			int xx = rmq.get (new_x1, new_y1, x2, y2); 
			debug (new_x1, new_y1, x2, y2, xx);
			return xx >= x;
		};
		while (low < high) {
			int mid = (low + high) / 2;
			if (f (mid)) low = mid + 1;
			else high = mid;
		}
		if (f (low) == false) low--;
		assert (f (low));
		cout << low << '\n';
	}
	return 0;
}
