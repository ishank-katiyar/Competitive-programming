#warning Incomplete soln

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
	using SparseTable<T, F>::n;
	using SparseTable<T, F>::st;
	using SparseTable<T, F>::func;
public:
	RangeQuery () {}
	RangeQuery (const vector<T>& a, const F& f) : SparseTable<T, F> (a, f) {}
	T get (const int l, const int r) {
		assert (0 <= l && l <= r && r < n);
		int lg = 31 - __builtin_clz (r - l + 1);
		return func (st[lg][l], st[lg][r - (1 << lg) + 1]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort (a.begin(), a.end());
	vector<pair<int, int>> b (n - 1);
	for (int i = 1; i < n; i++) {
		b[i - 1].first = a[i].first - a[i - 1].first;
		b[i - 1].second = i;
	}
	RangeQuery <pair<int, int>> rmq (b, [](pair<int, int> x, pair<int, int> y) -> pair<int, int> { return x.first >= y.first ? x : y; });
	auto f = [&] (vector<int> x) -> bool {
		assert (x.size() == 3);
		// debug (x);
		sort (x.begin(), x.end());
		int sum = accumulate (x.begin() , x.end() ,0);
		return x[2] <= 2 * x[0] && all_of (x.begin(), x.end(),[](int y) {return y > 0;}) && sum <= n && all_of (x.begin(), x.end(), [&] (int y) {return y <= n - 2;});
	};
	auto Max = [] (tuple<int, int, int> A, tuple<int, int, int> B) -> tuple<int, int, int>{
		assert (get<0> (A) >= 0 && get<1> (A) >= 0 && get<2> (A) >= 0);
		if (get<2> (A) == get<2> (B)) {
			if (get<1> (A) == get<1> (B)) {
				if (get<0> (A) == get<0> (B)) {
					return A;
				}
				return get<0> (A) >= get<0> (B) ? A : B;
			}
			return get<1> (A) >= get<1> (B) ? A : B;
		}
		return get<2> (A) >= get<2> (B) ? A : B;
	};
	tuple<int, int, int> ans = {-1, -1, -1};
	tuple<int, int, int> idx = {-1, -1, -1};
	for (int k = n - 1; k >= 2; k--) {
		for (int j = k - 1; j >= 1; j--) {
			int x1 = n - k;
			int x2 = k - j;
			assert (x1 > 0 && x2 > 0);
			if (2 * min (x1, x2) < max (x1, x2)) continue;
			int left_i = j - 2 * min (x1, x2);
			int right_i = j - (max (x1, x2) + 1) / 2;
			if (right_i < 0) {
				if (f ({n - x1 - x2, x1, x2}) == false) continue;
				assert (false);
				tuple<int, int, int> cur_ans = {a[0].first, a[j].first - a[j - 1].first, a[k].first - a[k - 1].first};
				if (Max (cur_ans, ans) == cur_ans) {
					ans = cur_ans;
					idx = {-1, j - 1, k - 1};
				}
				continue;
			}
			left_i = max (left_i, 0);
			assert (right_i >= left_i && right_i < j);
			// debug (k, j, left_i, right_i, x1, x2)
			// assert (f ({j - left_i, x1, x2}) == true);
			// assert (f ({j - right_i, x1, x2}) == true);
			// if (left_i > 0) assert (f ({j - left_i + 1, x1, x2}) == false);
			// assert (f ({j - right_i - 1, x1, x2}) == false);
			pair<int, int> pp = {-1, -1};
			if (right_i > 0) {
				pp = rmq.get (max (left_i - 1, 0), right_i - 1);
			}
			if (left_i == 0 && a[0].first > pp.first) {
				assert (f ({j, x1, x2}));
				pp = {a[0].first, 0};
			}
			debug (left_i, right_i, j, k)
			debug (pp)
			tuple<int, int, int> cur_ans = {pp.first, a[j].first - a[j - 1].first, a[k].first - a[k - 1].first};
			assert (f ({j - pp.second, k - j, n - k}) == true);
			debug (pp.second - 1, j - 1, k - 1)
			if (Max (cur_ans, ans) == cur_ans) {
				ans = cur_ans;
				idx = {pp.second - 1, j - 1, k - 1};
			}
		}
	}
	debug (idx)
	assert (idx != make_tuple(-1, -1, -1));
	vector<int> Ans (n);
	for (int i = 0; i <= get<0> (idx); i++) {
		Ans[a[i].second] = -1;
	}
	for (int i = get<0> (idx) + 1; i <= get<1> (idx); i++) {
		Ans[a[i].second] = 3;
	}
	for (int i = get<1> (idx) + 1; i <= get<2> (idx); i++) {
		Ans[a[i].second] = 2;
	}
	for (int i = get<2> (idx) + 1; i <= n - 1; i++) {
		Ans[a[i].second] = 1;
	}
	for (auto& i: Ans) {
		cout << i << ' ';
	}
	cout << '\n';
	return 0;
}
