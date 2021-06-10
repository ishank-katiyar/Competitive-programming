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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int mx1 = 0;
		bool ok1 = false, ok2 = false;
		for (int i = 0; i < n; i++) {
			ok1 |= (a[i] == 1);
			ok2 |= (a[i] == n);
			if (ok1 && ok2) {
				mx1 = i + 1;
				break;
			}
		}
		int mx2 = 0;
		ok1 = false, ok2 = false;
		for (int i = n - 1; i >= 0; i--) {
			ok1 |= (a[i] == 1);
			ok2 |= (a[i] == n);
			if (ok1 && ok2) {
				mx2 = n - i;
				break;
			}
		}
		int idx1 = -1, idx2 = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) idx1 = i;
			if (a[i] == n) idx2 = i;
		}
		cout << min ({mx1, mx2, (idx1 + 1 + n - idx2), (n - idx1 + idx2 + 1)}) << '\n';
	}
	return 0;
}
