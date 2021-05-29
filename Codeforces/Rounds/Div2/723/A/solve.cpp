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
		vector<int> a (2 * n);
		for (int i = 0; i < 2 * n; i++) {
			cin >> a[i];
		}
		sort (a.begin(), a.end());
		int i = 0, j = 2 * n - 1;
		while (i < j) {
			cout << a[i] << ' ';
			cout << a[j] << ' ';
			i++, j--;
		}
		cout << "\n";
	}	
	return 0;
}
