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

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	assert (argc == 4);
	ifstream input (argv[1]);
	ifstream output_solve (argv[2]);
	ifstream output_brute (argv[3]);
	int n;
	input >> n;
	vector<int> a (n);
	for (int i = 0; i < n; i++) {
		input >> a[i];
	}
	input.close();
	// vector<int> Output_brute (n), Output_solve (n);
	vector<pair<int, int>> a_brute(n), a_solve(n);
	for (int i = 0; i < n; i++) {
		output_solve >> a_solve[i].second;
		a_solve[i].first = a[i];
	}
	for (int i = 0; i < n; i++) {
		output_brute >> a_brute[i].second;
		a_brute[i].first = a[i];
	}
	output_brute.close();
	output_solve.close();
	debug (n, a)
	debug (a_brute, a_solve)


	sort (a_brute.rbegin(), a_brute.rend());
	tuple<int, int, int> brute;
	assert (a_brute.front().second == 1);
	int idx_2 = -1, idx_3 = -1, idx__1 = -1;
	for (int i = 0; i < n; i++) {
		if (a_brute[i].second == 2 && idx_2 == -1) idx_2 = i;
		if (a_brute[i].second == 3 && idx_3 == -1) idx_3 = i;
		if (a_brute[i].second == -1 && idx__1 == -1) idx__1 = i;
	}
	assert (idx_2 != -1 && idx_3 != -1);
	get<0> (brute) = a_brute[idx_2 - 1].first - a_brute[idx_2].first;
	get<1> (brute) = a_brute[idx_3 - 1].first - a_brute[idx_3].first;
	if (idx__1 != -1) {
		get<2> (brute) = a_brute[idx__1 - 1].first - a_brute[idx__1].first;
	} else {
		get<2> (brute) = a_brute.back().first;
	}


	sort (a_solve.rbegin(), a_solve.rend());
	tuple<int, int, int> solve;
	assert (a_solve.front().second == 1);
	idx_2 = -1, idx_3 = -1, idx__1 = -1;
	for (int i = 0; i < n; i++) {
		if (a_solve[i].second == 2 && idx_2 == -1) idx_2 = i;
		if (a_solve[i].second == 3 && idx_3 == -1) idx_3 = i;
		if (a_solve[i].second == -1 && idx__1 == -1) idx__1 = i;
	}
	assert (idx_2 != -1 && idx_3 != -1);
	get<0> (solve) = a_solve[idx_2 - 1].first - a_solve[idx_2].first;
	get<1> (solve) = a_solve[idx_3 - 1].first - a_solve[idx_3].first;
	if (idx__1 != -1) {
		get<2> (solve) = a_solve[idx__1 - 1].first - a_solve[idx__1].first;
	} else {
		get<2> (solve) = a_solve.back().first;
	}
	debug (solve, brute)
	if (solve != brute) {
		cout << "Ouput mismatch!!\n";
		assert (false);
	}
	cout << "Output Match!!" << '\n';
	return 0;
}
