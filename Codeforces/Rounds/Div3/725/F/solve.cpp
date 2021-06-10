#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		auto f = [] (int n) -> int {
			auto ff = [] (char ch, int cnt) -> int {
				return stoi (string (cnt, ch));
			};
			int sz = to_string (n).size();
			int ans = 0;
			for (int i = 0; i < sz; i++) {
				ans += ff (to_string (n)[i], sz - i);
			}
			return ans;
		};
		int l, r;
		cin >> l >> r;
		cout << f (r) - f (l) << '\n';
	}
	return 0;
}
