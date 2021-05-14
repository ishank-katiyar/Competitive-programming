#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<long long int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin() , a.end());
	long long int mul = 1;
	for(int i = 0; i < n; i++) {
		long long int x = a[i];
		long double x1= (long double) mul * x;
		if(x1 > 1e18 || x1 < 0) {
			cout << "-1";
			return 0;
		}
		mul = (long long int) x1;
	}
	cout << mul;
	return 0;
}
