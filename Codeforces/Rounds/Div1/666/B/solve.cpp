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
		int sum = 0;
		vector<int> a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if (any_of (a.begin(), a.end(), [&] (int x) -> bool {return x > sum / 2;})) {
			cout << "T" << '\n';
		} else {
			cout << (sum % 2 ? "T" : "HL") << '\n';
		}
	}
	return 0;
}
