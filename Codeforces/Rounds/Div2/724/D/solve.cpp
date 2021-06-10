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
		vector<int> b (n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		bool ok = true;
		set<int> s;
		s.insert (b.front());
		for (int i = 1; i < n; i++) {
			int l = b[i], r = b[i - 1];
			if (l == r) continue;
			if (l > r) swap(l, r);
			auto it = s.lower_bound (l + 1);
			if (it != s.end() && *it < r) {
				ok = false;
				break;
			}
			s.insert (b[i]);
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
