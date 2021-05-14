#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int64_t a, b;
		cin >> a >> b;
		if (b == 1) {
			cout << "NO" << '\n';
		}	else {
			b *= 2;
			cout << "YES\n" << a << ' ' << (b - 1) * a << ' ' << a * b << '\n'; 
		}
	}
	return 0;
}
