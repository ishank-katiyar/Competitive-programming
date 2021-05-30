#include <bits/stdc++.h>

// using namespace std;

class ToString {
	constexpr static int float_precision = 6;
public:
	template<typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
	static std::string to_string(const T x) { return std::to_string(x); }

	template<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
	static std::string to_string(const T x) { 
		std::stringstream tmp;
		tmp << std::fixed << std::setprecision(float_precision) << x;
		return tmp.str();
	}

	static std::string to_string(const std::string s) { return "\"" + s + "\""; }
	static std::string to_string(const char* ch) { return std::string(ch); }
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

	static std::string to_string(const std::vector<bool>& v) { bool first = true; std::string res = "{"; for (const bool& x: v) { if (!first) res += ", ";  first = false, res += to_string(x); } res += "}"; return res; }
	template <size_t N> 
	static std::string to_string(const std::bitset<N>& v) { std::string res = ""; for (size_t i = 0; i < N; i++) { res += static_cast<char> ('0' + v[i]); } return to_string(res); }

	// create custom type checker - "https://stackoverflow.com/a/48458312/11587347"
	template<typename> struct is_stack: std::false_type {};
	template<typename ...T> struct is_stack<std::stack<T...>>: std::true_type {};
	template<typename> struct is_queue: std::false_type {};
	template<typename ...T> struct is_queue<std::queue<T...>>: std::true_type {};
	template<typename> struct is_priority_queue: std::false_type {};
	template<typename ...T> struct is_priority_queue<std::priority_queue<T...>>: std::true_type {};
	// template<typename> struct has_no_begin_end: std::false_type {};
	// template<typename ...T> struct has_no_begin_end<std::stack<T...>>: std::true_type {};
	// template<typename ...T> struct has_no_begin_end<std::queue<T...>>: std::true_type {};
	// template<typename ...T> struct has_no_begin_end<std::priority_queue<T...>>: std::true_type {};

	template<typename ...T>
	static std::string to_string(std::queue<T...> a) {
		if (a.empty()) return to_string (std::vector<int>(0));
		auto tmp_back = a.front();
		// auto tmp = decltype(tmp_back);
		std::vector<decltype(tmp_back)> res;
		while(a.empty() == false) { res.push_back(a.front()); a.pop(); }
		return to_string(res);
	}
	template<typename ...T>
	static std::string to_string(std::stack<T...> a) {
		if (a.empty()) return to_string (std::vector<int>(0));
		auto tmp_top = a.top();
		// auto tmp = decltype(tmp_top);
		std::vector<decltype(tmp_top)> res;
		while(a.empty() == false) { res.push_back(a.top()); a.pop(); }
		return to_string(res);
	}
	template<typename ...T>
	static std::string to_string(std::priority_queue<T...> a) {
		if (a.empty()) return to_string (std::vector<int>(0));
		auto tmp_top = a.top();
		// auto tmp = decltype(tmp_top);
		std::vector<decltype(tmp_top)> res;
		while(a.empty() == false) { res.push_back(a.top()); a.pop(); }
		return to_string(res);
	}

	// check if container have contant iterator and begin and end - "https://stackoverflow.com/a/25216349/11587347"
	template<typename...> struct void_ { using type = void; };
	template<typename... Args> using Void = typename void_<Args...>::type;
	template<typename T, typename = void> struct has_const_iterator : std::false_type {};
	template<typename T> struct has_const_iterator<T, Void<typename T::const_iterator>> : std::true_type {};
	struct has_begin_end_impl { template<typename T, typename Begin = decltype(std::declval<const T&>().begin()), typename End   = decltype(std::declval<const T&>().end())> static std::true_type test(int); template<typename...> static std::false_type test(...); };
	template<typename T> struct has_begin_end : decltype(has_begin_end_impl::test<T>(0)) {};

	template<typename T, typename std::enable_if<has_const_iterator<T>::value && has_begin_end<T>::value>::type* = nullptr>
	static std::string to_string(const T& a) {
		std::string res = "{";
		bool first = true;
		for(const auto& x: a) { if(first == false) res += ", "; first = false, res += to_string(x); }
		res += "}";
		return res;
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
// template<typename T>
// void debug (const T& x) {
// 	cerr << ToString::To_string(x) << endl;
// }

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int x = 0;
	int64_t lx = 0;
	long long llx = 0;
	double d = 0.0;
	long double ld = 0.0;
	debug (x, lx, llx, d, ld);

	bool ok = false;
	char ch = 'b';
	std::string s = "hello";
	debug ("good", 'a', ch, true, ok, s);

	std::pair<int, int> p = {1, 2};
	debug (p);

	std::tuple<int, int, int> a, b ({1, 2, 3});
	debug (a, b);
	debug (b)

	std::vector<bool> vb({0, 1});
	std::bitset<10> bs (10);
	debug (vb, bs)

	std::queue<int> qu;
	qu.push (1), qu.push (2), qu.push (3);
	std::stack <int> st;
	st.push (1), st.push (2), st.push (3);
	std::priority_queue<int, std::vector<int> > pq;
	pq.push (1), pq.push (2), pq.push (3);
	debug (qu, st, pq)
	return 0;
}
