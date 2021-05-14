#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, w, wr;
		cin >> n >> w >> wr;
		w -= wr;
		map<int64_t, int> mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}
		int64_t sum = 0;
		for (auto& i: mp) {
			sum += i.first * (i.second / 2);
		}
		sum *= 2;
		cout << (sum >= w ? "YES" : "NO") << '\n';
	}
	return 0;
}
