#include "bits/stdc++.h"
using namespace std;

#define pi acos(-1)

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long double ans = (long double) cos((long double) pi / (4 * n)) / sin((long double) pi / (2 * n));
		cout << fixed << setprecision(10) << ans << '\n';
	}
	return 0;
}
