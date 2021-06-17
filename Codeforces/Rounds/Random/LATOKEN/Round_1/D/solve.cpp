#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<pair<int, int>> edge;
	auto ask = [&] (int x) -> vector<int> {
		cout << "? " << x << endl;
		vector<int> dist (n);
		for (int i = 0; i < n; i++) {
			cin >> dist[i];
			if (dist[i] == 1) {
				edge.insert (make_pair (min (i + 1, x), max (i + 1, x)));
			}
		}
		return dist;
	};
	auto dd = ask (1);
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		(dd[i] % 2 == 0 ? even : odd) += 1;
	}
	bool ok = even <= odd ? 0 : 1;
	for (int i = 1; i < n; i++) {
		if (dd[i] % 2 == ok) {
			ask (i + 1);
		}
	}
	assert (int(edge.size()) == n - 1);
	cout << "!" << endl;
	for (auto& i : edge) cout << i.first << ' ' << i.second << endl;
	return 0;
}
