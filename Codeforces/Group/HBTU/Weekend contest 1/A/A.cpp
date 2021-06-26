#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , q;
	scanf("%d %d" , &n , &q);
	long long int sum = 0;
	vector<long long int> pref(n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d" , &x);
		sum += x;
		pref[i] = sum;
	}
	sum = 0;
	for(int i = 0; i < q; i++) {
		long long int k;
		scanf("%I64d" , &k);
		sum += k;
		int ans = upper_bound(pref.begin() , pref.end() , sum) - pref.begin();
		printf("%d\n" , (n - ans) ? n - ans : n);
		if(sum >= pref[n - 1]) sum = 0;
	} 
	return 0;
}