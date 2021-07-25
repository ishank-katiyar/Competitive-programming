#include <bits/stdc++.h>

using namespace std;

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

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		string S;
		cin >> S;
		auto f1 = [] (string s) -> int {
			for (int i = 0; i < 10; i += 2) {
				if (s[i] == '?') s[i] = '1';
			}
			for (int i = 1; i < 10; i += 2) {
				if (s[i] == '?') s[i] = '0';
			}
			int winA = 0, winB = 0, remA = 5, remB = 5;
			for (int i = 0; i < 10; i++) {
				if (i % 2 == 0) {
					// A
					if (s[i] == '1') {
						winA += 1;
					}					
					remA -= 1;
				}	else {
					// B
					if (s[i] == '1') {
						winB += 1;
					}					
					remB -= 1;
				}
				if (winA > winB + remB) return i + 1;
				if (winB > winA + remA) return i + 1;
			}
			return 10;
		};
		auto f2 = [] (string s) -> int {
			for (int i = 0; i < 10; i += 2) {
				if (s[i] == '?') s[i] = '0';
			}
			for (int i = 1; i < 10; i += 2) {
				if (s[i] == '?') s[i] = '1';
			}
			int winA = 0, winB = 0, remA = 5, remB = 5;
			for (int i = 0; i < 10; i++) {
				if (i % 2 == 0) {
					// A
					if (s[i] == '1') {
						winA += 1;
					}					
					remA -= 1;
				}	else {
					// B
					if (s[i] == '1') {
						winB += 1;
					}					
					remB -= 1;
				}
				if (winA > winB + remB) return i + 1;
				if (winB > winA + remA) return i + 1;
			}
			return 10;
		};
		// int ans = f (S);
		// for (int i = 0; i < 10; i += 2) {
		// 	swap(S[i], S[i + 1]);
		// }
		cout << min (f1(S), f2 (S)) << '\n';
	}
	return 0;
}
