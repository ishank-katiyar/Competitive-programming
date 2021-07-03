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
		int n;
		cin >> n;
		vector<int64_t> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		RangeQuery rmq_gcd (a, [] (int64_t x, int64_t y) -> int64_t { return __gcd (x, y); });
		RangeQuery rmq_sum (a, [] (int64_t x, int64_t y) -> int64_t { return x + y; });
		int64_t ans = LLONG_MAX;
		ans = min (ans, (rmq_sum.get (1, n - 1) / rmq_gcd.get (1, n - 1)) + 1);
		ans = min (ans, (rmq_sum.get (0, n - 2) / rmq_gcd.get (0, n - 2)) + 1);
		for (int i = 1; i < n - 1; i++) {
			ans = min (ans, ((rmq_sum.get (0, i - 1) + rmq_sum.get (i + 1, n - 1)) / (__gcd(rmq_gcd.get (0, i - 1), rmq_gcd.get (i + 1, n - 1)))) + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}
