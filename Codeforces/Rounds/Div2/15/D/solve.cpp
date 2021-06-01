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

template<typename T>
class MinQueue {
protected:
	deque<T> d;
public:
	MinQueue () {}
};

template<typename T>
class RangeQuery : public MinQueue<T> {
	using MinQueue<T>::d;
public:
	RangeQuery () {}
	T get () {
		assert (d.empty () == false);
		return d.front();
	}
	void add (T x) {
		while (d.empty() == false && d.back() > x) d.pop_back();
		d.push_back(x);
	}
	void remove (T x) {
		if (d.empty() == false && d.front() == x) d.pop_front();
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int>> h (n, vector<int> (m));
	vector<vector<int64_t>> dp (n, vector<int64_t> (m, 0));
	for (int i = 0; i < n; i++) {
		int64_t sum = 0;
		for (int j = 0; j < m; j++) {
			cin >> h[i][j];
			sum += h[i][j];
			if (i > 0) dp[i][j] += dp[i - 1][j];
			dp[i][j] += sum;
		}
	}
	auto range_sum = [&] (int x1, int y1, int x2, int y2) -> int64_t {
		assert (0 <= x1 && x1 <= x2 && x2 < n && 0 <= y1 && y1 <= y2 && y2 < m);
		int64_t res = dp[x2][y2];
		if (x1 > 0) res -= dp[x1 - 1][y2];
		if (y1 > 0) res -= dp[x2][y1 - 1];
		if (x1 > 0 && y1 > 0) res += dp[x1 - 1][y1 - 1];
		return res;
	};
	vector<vector<int>> hor (n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		RangeQuery <int> rmq;
		for (int j = 0; j < b - 1; j++) {
			rmq.add (h[i][j]);
		}
		for (int j = 0; j < m - b + 1; j++) {
			if (j > 0) rmq.remove (h[i][j - 1]);
			rmq.add (h[i][j + b - 1]);
			hor[i][j] = rmq.get ();
		}
	}
	vector<vector<int>> ver (n, vector<int> (m));
	for (int j = 0; j < m - b + 1; j++) {
		RangeQuery <int> rmq;
		for (int i = 0; i < a - 1; i++) {
			rmq.add (hor[i][j]);
		}
		for (int i = 0; i < n - a + 1; i++) {
			if (i > 0) rmq.remove (hor[i - 1][j]);
			rmq.add (hor[i + a - 1][j]);
			ver[i][j] = rmq.get ();
		}
	}
	debug (hor)
	debug (ver)
	struct cmp {
		bool operator() (const pair<int64_t, pair<int, int>> a, const pair<int64_t, pair<int, int>> b) const {
			if (a.first == b.first) {
				if (a.second.first == b.second.first) return a.second.second > b.second.second;
				return a.second.first > b.second.first;
			}
			return a.first > b.first;
		}
	};
	priority_queue <pair<int64_t, pair<int, int>>, vector<pair<int64_t, pair<int, int>>>, cmp> pq;
	for (int i = 0; i < n - a + 1; i++) {
		for (int j = 0; j < m - b + 1; j++) {
			pq.push (make_pair (range_sum (i, j, i + a - 1, j + b - 1) - 1ll * a * b * ver[i][j], make_pair (i, j)));
		}
	}
	debug (pq)
	vector<vector<bool>> used (n, vector<bool> (m, false));
	vector<tuple<int, int, int64_t>> ans;
	while (pq.empty() == false) {
		auto [cur_sum, p] = pq.top ();
		if (used[p.first][p.second] == true || used[p.first][p.second + b - 1] == true || used[p.first + a - 1][p.second] == true || used[p.first + a - 1][p.second + b - 1] == true) {
			pq.pop();
			continue;
		}
		bool usable = true;
		for (int i = p.first; i < p.first + a; i++) {
			for (int j = p.second; j < p.second + b; j++) {
				usable &= used[i][j] == false;
			}
		}
		assert (usable == true);
		if (usable) {
			ans.push_back(make_tuple (p.first, p.second, cur_sum));
			for (int i = p.first; i < p.first + a; i++) {
				for (int j = p.second; j < p.second + b; j++) {
					used[i][j] = true;
				}
			}
		}
		pq.pop ();
	}
	cout << ans.size() << '\n';
	for (auto& i: ans) cout << get<0> (i) + 1 << ' ' << get<1> (i) + 1 << ' ' << get<2> (i) << '\n';
	return 0;
}
