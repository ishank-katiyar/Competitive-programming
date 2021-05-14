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
		int x;
		cin >> x;
		vector<int> a (n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n - 1; i++) {
			sum += a[i];
			if (sum == x) {
				swap (a[i], a[i + 1]);
			}
		}
		sum += a.back();
		if (sum == x) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
