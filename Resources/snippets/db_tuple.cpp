#include <bits/stdc++.h>

using namespace std;

vector<string> __vector_tuple;
template<int index, class... A> struct print_tuple {
	auto operator() (tuple<A...> a) {
		__vector_tuple.push_back(to_string(get<index>(a))); 
		print_tuple<index-1, A...>{}(a); 
	}
};

template<class... A> struct print_tuple<0, A...> {
	auto operator() (tuple<A...> a) { __vector_tuple.push_back(to_string(get<0>(a))); }
};

template<class... T> string to_string(tuple<T...> a) {
	const int ttsz = tuple_size<decltype(a)>::value;
	print_tuple<ttsz-1, T...>{}(a);
	string __ss = to_string(__vector_tuple);
	__vector_tuple.clear();
	return __ss;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}