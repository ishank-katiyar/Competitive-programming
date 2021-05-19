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
		vector<int> a (n);
		bool ok = true;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ok &= (a[i] == i + 1);
		}
		if (ok) {
			cout << 0 << '\n';
			continue;
		}
		int ans = 1;
		if (a.front() == n && a.back() == 1) {
			ans = 3;
		} else if (a.front() == 1 || a.back() == n) {
			ans = 1;
		}	else ans = 2;
		cout << ans << '\n';
	}
	return 0;
}
