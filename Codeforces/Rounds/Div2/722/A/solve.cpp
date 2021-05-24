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
		map <int, int> mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}		
		cout << n - mp.begin()->second << '\n';
	}
	return 0;
}
