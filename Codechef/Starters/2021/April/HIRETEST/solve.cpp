#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int x, y;
		cin >> x >> y;
		string ans;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			vector<int> a {(int)count(s.begin(), s.end(), 'F'), (int)count(s.begin(), s.end(), 'P'), (int)count(s.begin(), s.end(), 'U')};
			ans.push_back((a[0] >= x || (a[0] >= x - 1 && a[1] >= y)) ? '1' : '0');
		}
		cout << ans << '\n';
	}
	return 0;
}