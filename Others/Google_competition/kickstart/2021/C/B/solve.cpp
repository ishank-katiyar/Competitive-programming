#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	for (int ttt = 1; ttt <= tt; ttt++) {
		int64_t G;
		cin >> G;
		int ans = 0;
		for (int64_t day = 1; ; day++) {
			int64_t nu = 2 * G + day - (day * day);
			if (nu > 0 && nu % (2 * day) == 0) {
				ans += 1;
			}
			if (nu <= 0) break;
		}
		cout << "Case #" << ttt << ": " << ans << '\n';
	}
	return 0;
}
