#include <bits/stdc++.h>

using namespace std;

class ToString {
	constexpr static int float_precision = 6;
public:
	template<typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
	static std::string to_string(const T x) { return std::to_string(x); }

	template<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
	static std::string to_string(const T x) { std::stringstream tmp; tmp << std::fixed << std::setprecision(float_precision) << x; return tmp.str(); }

	static std::string to_string(const std::string s) { return "\"" + s + "\""; }
	static std::string to_string(const char* ch) { return to_string(std::string(ch)); }
	static std::string to_string(const char ch) { return "\'" + std::string(1, ch) + "\'"; }
	static std::string to_string(const bool b) { return (b ? "true" : "false"); }

	template<typename X, typename Y>
	static std::string to_string(const std::pair<X, Y> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

	template<int index, typename... X>
	struct print_tuple { auto operator() (std::tuple<X...> a, std::vector<std::string>& __vector_tuple) { __vector_tuple.push_back(to_string(std::get<index>(a))); print_tuple<index - 1, X...>{}(a, __vector_tuple); } };
	template<typename... X>
	struct print_tuple<0, X...> { auto operator() (std::tuple<X...> a, std::vector<std::string>& __vector_tuple) { __vector_tuple.push_back(to_string(std::get<0>(a))); } };
	template<typename... T>
	static std::string to_string(const std::tuple<T...> a) { std::vector<std::string> __vector_tuple; print_tuple<std::tuple_size<decltype(a)>::value - 1, T...>{}(a, __vector_tuple); std::reverse (__vector_tuple.begin(), __vector_tuple.end()); return to_string(__vector_tuple); }

	static std::string to_string(const std::vector<bool> v) { bool first = true; std::string res = "{"; for (const bool x: v) { if (!first) res += ", ";  first = false, res += to_string(x); } res += "}"; return res; }
	template <size_t N>
	static std::string to_string(const std::bitset<N> v) { std::string res = ""; for (size_t i = 0; i < N; i++) { res += static_cast<char> ('0' + v[i]); } return to_string(res); }

	template<typename ...T>
	static std::string to_string(const std::queue<T...> A) { auto a = A; if (a.empty()) return to_string (std::vector<int>(0)); auto tmp_back = a.front(); std::vector<decltype(tmp_back)> res; while(a.empty() == false) { res.push_back(a.front()); a.pop(); } return to_string(res); }
	template<typename ...T>
	static std::string to_string(const std::stack<T...> A) { auto a = A; if (a.empty()) return to_string (std::vector<int>(0)); auto tmp_top = a.top(); std::vector<decltype(tmp_top)> res; while(a.empty() == false) { res.push_back(a.top()); a.pop(); } return to_string(res); }
	template<typename ...T>
	static std::string to_string(const std::priority_queue<T...> A) { auto a = A; if (a.empty()) return to_string (std::vector<int>(0)); auto tmp_top = a.top(); std::vector<decltype(tmp_top)> res; while(a.empty() == false) { res.push_back(a.top()); a.pop(); } return to_string(res); }

	// check if container have contant iterator and begin and end - "https://stackoverflow.com/a/25216349/11587347"
	template<typename...> struct void_ { using type = void; };
	template<typename... Args> using Void = typename void_<Args...>::type;
	template<typename T, typename = void> struct has_const_iterator : std::false_type {};
	template<typename T> struct has_const_iterator<T, Void<typename T::const_iterator>> : std::true_type {};
	struct has_begin_end_impl { template<typename T, typename Begin = decltype(std::declval<const T&>().begin()), typename End   = decltype(std::declval<const T&>().end())> static std::true_type test(int); template<typename...> static std::false_type test(...); };
	template<typename T> struct has_begin_end : decltype(has_begin_end_impl::test<T>(0)) {};

	template<typename T, typename std::enable_if<has_const_iterator<T>::value && has_begin_end<T>::value>::type* = nullptr>
	static std::string to_string(const T a) { std::string res = "{"; bool first = true; for(const auto& x: a) { if(first == false) res += ", "; first = false, res += to_string(x); } res += "}"; return res; }
};

void debug() { std::cerr << "]" << std::endl; }
template<class H, class... T>
void debug(H head, T... tail) { std::cerr << ToString::to_string(head) << " "; debug(tail...); }
#ifdef LOCAL
	#define debug(...) std::cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else
	#define debug(...)
#endif

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
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int64_t> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<pair<int64_t, int>> suf (n);
		suf[n - 1].first = a[n - 1];
		suf[n - 1].second = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			suf[i].first += suf[i + 1].first + a[i];
			suf[i].second = i;
		}
		RangeQuery <pair<int64_t, int>> rmq (suf, [] (pair<int64_t, int> x, pair<int64_t, int> y) -> pair<int64_t, int> { return x.first > y.first ? x : y; });
		vector<vector<int64_t>> dp (k, vector<int64_t> (n));
		// dp[0][0] = a[0];
		// for (int i = 1; i < n; i++) {
		// 	auto [xx, idx] = rmq.get (0, i);
		// 	if (i + 1 < n) xx -= suf[i + 1].first;
		// 	dp[i][0] = xx;
		// 	debug (i, xx, idx);
		// 	for (int j = 0; j < min (idx, k); j++) {
		// 		dp[i][j + 1] = dp[idx - 1][j] + xx * (j + 2);
		// 	}
		// 	for (int j = 0; j < k; j++) {
		// 		dp[i][j] = max (dp[i][j], dp[i - 1][k]);
		// 	}
		// }
		// cout << dp[n - 1][k - 1] << '\n';
		// vector<vector<int64_t>> dp (n, vector<int64_t> (k));
		for (int i = 0; i < n; i++) {
			auto [xx, idx] = rmq.get (0, i);
			if (i + 1 < n) xx -= suf[i + 1].first;
			dp[0][i] = xx;
		}
		for (int j = 1; j < k; j++) {
			int64_t mx = dp[j - 1][j];
			mx = max (mx, dp[j - 1][j - 1]);
			// for (int i = 0; i <= j; i++) {
			// 	mx = max (mx, dp[j - 1][i]);
			// }
			dp[j][j] = dp[j - 1][j - 1] + a[j] * (j + 1);
			for (int i = j + 1; i < n; i++) {
				dp[j][i] = max (dp[j][i - 1] + a[i] * (j + 1), mx + a[i] * (j + 1));
				mx = max (mx, dp[j - 1][i]);
			}
		}
		debug (dp)
		int64_t ans = LLONG_MIN;
		for (int i = k - 1; i < n; i++) {
			ans = max (ans, dp[k - 1][i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
