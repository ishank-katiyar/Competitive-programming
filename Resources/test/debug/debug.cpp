#include <bits/stdc++.h>

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


struct cmp {
	bool operator() (const int x, const int y) const {
		return x > y;
	}
};


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
	debug (qu);
	qu.pop();
	debug (qu);
	std::stack <int> st;
	st.push (1), st.push (2), st.push (3);
	std::priority_queue<int, std::vector<int> > pq;
	pq.push (1), pq.push (2), pq.push (3);
	debug (qu, st, pq)

	std::priority_queue<int, std::vector<int>, cmp> pqq;
	pqq.push (1), pqq.push (2), pqq.push (3);
	debug (pqq)


	std::vector<int> vec (5);
	std::iota (vec.begin(), vec.end(), 0);
	std::set<int> ss (vec.begin(), vec.end());
	std::multiset<int> mst (vec.begin(), vec.end());
	debug (vec, ss, mst)
	std::deque<int> dd (vec.begin(), vec.end());
	std::map<int, int> mp;
	for (int i = 0; i < int (vec.size ()); i++) {
		mp[vec[i]] = i;
	}
	debug (dd, mp);
	std::map <int, std::vector<int> > mp1;
	for (int i = 0; i < int (vec.size ()); i++) {
		mp1[vec[i]].push_back(i);
	}
	debug (mp1)
	std::set<int,std::greater<int>> sg;
	sg.insert (1), sg.insert (2), sg.insert (3);
	std::map<int,std::string,std::greater<int>> misg;
	for (int i = 0; i < int (vec.size ()); i++) {
		misg[vec[i]] = std::to_string(i);
	}
	std::priority_queue<int,std::vector<int>,std::greater<int>> pqivg;
	pqivg.push (1), pqivg.push (2), pqivg.push (3);
	debug (sg, misg, pqivg)
	std::set<int,cmp> sg1;
	sg1.insert (1), sg1.insert (2), sg1.insert (3);
	debug (sg1)

	std::map <int, std::priority_queue<int>> mp2;
	for (int i = 0; i < int (vec.size ()); i++) {
		mp2[vec[i]].push(i);
	}
	debug (mp2)
	std::map<std::vector<std::set<int>>, std::vector<std::set<int>>> mp3;
	mp3[{{1}}] = {{2}};
	debug (mp3)

	// std::vector<int> vecc (2);
	// for (int i = 0; i < int (vecc.size ()); i++) {
	// 	std::cout << vecc[i] << '\n';
	// }
	// std::cout << vecc[-1] << '\n';
	// int rnd_int_a = INT_MAX, rnd_int_b = INT_MAX;
	// std::cout << rnd_int_a * rnd_int_b << '\n';
	// std::function<void(std::vector<int>)> f = [&] (std::vector<int> argument_vector) {
	// 	f(argument_vector);
	// };
	// f (vecc);

	// Mod mmm = -1;
	// debug (mmm)

	// std::vector<Mod> a_mod (3, -1);
	// debug (a_mod)

	struct node {
		int depth = -1;
		std::vector<int> adj;
		std::string to_string () const { return "{" + ToString::to_string(depth) + ", " + ToString::to_string(adj) + "}"; };
	};

	node a_node;
	debug (a_node)

	std::vector<node> vec_node (3);

	debug (vec_node)

	return 0;
}
