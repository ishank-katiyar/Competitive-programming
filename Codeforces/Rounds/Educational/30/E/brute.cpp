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
	int n;
	cin >> n;
	vector<pair<int, int>> a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort (a.begin (), a.end());
	auto f = [&] (vector<int> x) -> bool {
		assert (x.size() == 3);
		debug (x);
		sort (x.begin(), x.end());
		int sum = accumulate (x.begin() , x.end() ,0);
		return x[2] <= 2 * x[0] && all_of (x.begin(), x.end(),[](int y) {return y > 0;}) && sum <= n && all_of (x.begin(), x.end(), [&] (int y) {return y <= n - 2;});
	};
	auto max = [] (tuple<int, int, int> A, tuple<int, int, int> B) -> tuple<int, int, int>{
		if (get<2> (A) == get<2> (B)) {
			if (get<1> (A) == get<1> (B)) {
				if (get<0> (A) == get<0> (B)) {
					return A;
				}
				return get<0> (A) > get<0> (B) ? A : B;				
			}
			return get<1> (A) > get<1> (B) ? A : B;
		}
		return get<2> (A) > get<2> (B) ? A : B;
	};
	tuple<int, int, int> ans = {-1, -1, -1};
	tuple<int, int, int> idx = {-1, -1, -1};
	for (int i = -1; i < n - 3; i++) {
		for (int j = i + 1; j < n - 2; j++) {
			for (int k = j + 1; k < n - 1; k++) {
				if ((i == -1 && f ({j + 1, k - j, n - 1 - k})) || (i > -1 && f ({j - i, k - j, n - 1 - k}))) {
					tuple<int, int, int> cur_ans;
					if(i == -1) cur_ans =  {a[0].first, a[j + 1].first - a[j].first, a[k + 1].first - a[k].first};
					else cur_ans = {a[i + 1].first - a[i].first, a[j + 1].first - a[j].first, a[k + 1].first - a[k].first};
					if (max (cur_ans, ans) == cur_ans) {
						ans = cur_ans;
						idx = {i, j, k};
					}
				}
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
