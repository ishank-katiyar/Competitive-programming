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

	// SFINAE test to check if if class have to_string method - "https://stackoverflow.com/a/257382/11587347"
	template <typename T> 
	class have_to_string {
		typedef char one;
		struct two { char x[2]; };
		template <typename C> static one test( decltype(&C::to_string) ) ;
		template <typename C> static two test(...);    
	public:
		constexpr static bool value = sizeof(test<T>(0)) == sizeof(char);
	};

	template<typename T, typename std::enable_if<have_to_string<T>::value>::type* = nullptr>
	static std::string to_string (const T x) {
		return x.to_string ();
	}
};

void debug() { std::cerr << "]" << std::endl; }
template<class H, class... T>
void debug(H head, T... tail) { std::cerr << ToString::to_string(head) << " "; debug(tail...); }
#ifdef LOCAL
	#define debug(...) std::cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else
	#define debug(...)
#endif


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
	std::cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<string> a (n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> down (n, vector<int> (m, 0));

	for (int i = 0; i < m; i++) {
		if (a[0][i] == '.') down[0][i] = 1;
		else down[0][i] = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') down[i][j] = down[i - 1][j] + 1;
		}
	}
	debug (down)

	vector<vector<int>> left (n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				left[i][j] = (a[i][j] == '.');
			}	else if (a[i][j] == '.') {
				left[i][j] = left[i][j - 1] + 1;
			}
		}
	}
	debug (left)

	RangeQuery2d<int> rmq (left, [] (int x, int y) -> int { return max (x, y); });

	int ans = 0;

	auto f = [&] (int x1, int y1, int x2, int y2) -> int {
		return rmq.get (x1, y1, x2, y2);
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k = j;
			while (k >= 0 && a[i][k] != 'X') {
				int len = j - k + 1;
				int low = i, high = i - min (down[i][k], down[i][j]) + 1;
				// debug (low, high, i, j)
				assert (0 <= high && high < n);
				while (low > high) {
					// debug (low, high)
					int mid = (low + high) / 2;
					if (f (high, j, mid, j) >= len) {
						low = mid;
					}	else {
						high = mid + 1;
					}
				}
				int cur_ans = len * (i - low + 1);
				debug (i, k, j, low, cur_ans)
				ans = max (ans, cur_ans);
				k--;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
