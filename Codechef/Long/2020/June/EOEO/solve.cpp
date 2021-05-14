#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		long long int n;
		cin >> n;
		long long int x = 1;
		while(n % 2 == 0) x *= 2 , n /= 2;
		n *= x;
		x *= 2;
		n -= n % x;
		long long int  cnt = (n - x) / x;
		assert((n - x) % x == 0);
		cnt++;
		cout << cnt << '\n';
	}
	return 0;
}
