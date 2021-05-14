#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap (a, b);
		cout << ((b / a + (b % a != 0)) - 1 <= c ? "YES" : "NO") << '\n';
	}
	return 0;
}
