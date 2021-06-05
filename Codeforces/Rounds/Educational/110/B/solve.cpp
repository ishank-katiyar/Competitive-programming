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
		vector<int> odd, even;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			(x % 2 ? odd : even).push_back(x);
		}
		vector<int> a (even);
		for (auto& i: odd) a.push_back(i);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += (__gcd (a[i], 2 * a[j]) > 1);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
