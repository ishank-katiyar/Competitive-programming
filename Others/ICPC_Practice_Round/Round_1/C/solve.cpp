#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long double n, k, d, s;
	cin >> n >> k >> d >> s;
	assert (n > k);
	long double xx = d * n - k * s;
	long double ans = xx / (n - k);
	// if (xx < (long double)0) {
	// 	cout << "impossible" << '\n';
	// }
	// if (ans >= 0 && ans <= (long double)100) {
	const long double epsilon = 1e-9;
	// if (ans <= epsilon && (long double)100 - ans <= epsilon) {
	if ((ans >= 0 && ans <= (long double)100) || (abs (ans - 0) <= epsilon || abs (ans - 100) <= epsilon)) {
	// if (ans >= 0 && ans <= 100) {
		cout << fixed << setprecision (7) << ans << '\n';
	}	else {
		cout << "impossible" << '\n';
	}
	return 0;
}
