#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt0 = 0, cnt1 = 0;
		bool ok = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') cnt0 += 1;
			else cnt1 += 1;
			ok |= (2 * cnt1 >= ((i + 1)));
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
