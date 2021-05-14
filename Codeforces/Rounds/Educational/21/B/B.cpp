#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , k;
	scanf("%d %d" , &n , &k);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	long double ans = 0.0;
	int x1 = min(k , n - k + 1);
	for(int i = 0; i < n; i++) {
		int x = min({i + 1 , x1 , n - i});
		cerr << x << '\n';
		__int64 sum = (__int64) x * a[i];
		ans += (long double) sum;
	}
	cerr << ans << '\n';
	cout << fixed << setprecision(10) << (long double) ans / (n - k + 1);
	return 0;
}
