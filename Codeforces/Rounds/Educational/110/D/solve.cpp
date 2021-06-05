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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	string s;
	cin >> s;
	int n = s.size();
	assert (n == (1 << k) - 1);
	vector<int> next (n + 1);
	vector<pair<int, int>> prev (n + 1);
	next[n - 1] = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		int ii = n - i - 1;
		// ii *= 2;
		int idx1 = 2 * ii + 1, idx2 = 2 * ii + 2;
		idx1 = n - idx1 - 1, idx2 = n - idx2 - 1;
		// prev[i] = make_pair(i - (2 * ii + 1), i - (2 * ii + 2));
		prev[i] = make_pair (idx1, idx2);
		if (idx1 >= 0) next[idx1] = i;
		if (idx2 >= 0) next[idx2] = i;
	}
	debug (next)
	vector<int64_t> dp (n + 1);
	for (int i = 0; i < (1 << (k - 1)); i++) {
		dp[i] = 1 + (s[i] == '?');
	}
	for (int i = (1 << (k - 1)); i < n; i++) {
		assert (prev[i].first >= 0 && prev[i].second >= 0);
		if (s[i] == '0') dp[i] = dp[prev[i].second];
		if (s[i] == '1') dp[i] = dp[prev[i].first];
		if (s[i] == '?') dp[i] = dp[prev[i].first] + dp[prev[i].second];
	}
	debug (dp)
	int q;
	cin >> q;
	while (q--) {
		int idx;
		char ch;
		cin >> idx >> ch;
		idx--;
		s[idx] = ch;
		int cnt = 0;
		while (true) {
			cnt += 1;
			assert (cnt <= k + 10);
			if (idx < (1 << (k - 1))) {
				dp[idx] = 1 + (s[idx] == '?');
				if (idx == next[idx]) break;
				idx = next[idx];
				continue;
			}
			if (s[idx] == '0'){
				assert (prev[idx].second >= 0);
				dp[idx] = dp[prev[idx].second];
			}
			if (s[idx] == '1') {
				assert (prev[idx].first >= 0);
				dp[idx] = dp[prev[idx].first];
			}
			if (s[idx] == '?') {
				assert (prev[idx].first >= 0);
				assert (prev[idx].second >= 0);
				dp[idx] = dp[prev[idx].first] + dp[prev[idx].second];
			}
			if (idx == next[idx]) break;
			idx = next[idx];
		}
		debug (dp)
		cout << dp[n - 1] << '\n';
	}
	return 0;
}