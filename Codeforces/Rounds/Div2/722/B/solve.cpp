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
		int pos = 0, neg = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			(a[i] < 0 ? neg : pos) += 1;
		}
		sort (a.begin(), a.end());
		auto f = [&] (int x) -> int {
			vector<int> diff;
			int idx = -1;
			for (int i = 0; i < n; i++) {
				if (a[i] == x) idx = i;
			}
			assert (idx != -1);
			for (int i = 1; i <= idx; i++) {
				diff.push_back (a[i] - a[i - 1]);
			}
			int sum = 0, cnt = 0;
			while (diff.empty() == false) {
				sum += diff.back ();
				if (sum >= x) {
					cnt += 1;
					sum = 0;
				}
				diff.pop_back ();
			}
			return cnt + 1;
		};
		int ans = 1;
		auto it = upper_bound (a.begin (), a.end(), 0);
		if (it == a.begin ()) {
			cout << ans << '\n';
			continue;
		}
		it--;
		ans = max (ans, f (*it));
		if ((it + 1) != a.end ()) {
			ans = max (ans, f (*(it + 1)));
		}
		it = lower_bound (a.begin (), a.end (), 0);
		if (it != a.begin()) {
			ans = max (ans, f (*(it - 1)));
		}
		cout << ans << '\n';
	}	
	return 0;
}
