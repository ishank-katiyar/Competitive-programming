#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector<pair<int, int>> a(4);
		for (int i = 0; i < 4; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort (a.begin(), a.end());
		pair<int, int> p = make_pair (a[3].second, a[2].second);
		if (p.first > p.second) swap (p.first, p.second);
		cout << (p == make_pair(0, 1) || p == make_pair(2, 3) ? "NO" : "YES") << '\n';
	}
	return 0;
}
