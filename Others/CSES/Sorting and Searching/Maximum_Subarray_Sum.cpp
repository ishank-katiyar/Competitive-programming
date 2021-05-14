#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long int> a(n);
	for(int i = 0 ; i < n; i++) cin >> a[i];
	long long int small_sum = 0 , pref_sum = 0 , maxi_sum = -10000000000000000LL;
	for(int i = 0; i < n; i++) {
		pref_sum += a[i];
		maxi_sum = max(maxi_sum , pref_sum - small_sum);
		small_sum = min(small_sum , pref_sum);
	}  
	cout << maxi_sum;
	return 0;
}