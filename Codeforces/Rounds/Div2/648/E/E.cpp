#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<__int64> a(n);
	for(int i = 0; i < n; i++) scanf("%I64d" , &a[i]);
	__int64 ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i;  j < n; j++) {
			for(int k = j; k < n; k++) {
				ans = max(ans , (a[i] | a[j]) | a[k]);
			}
		} 
	}
	printf("%I64d" , ans);
	return 0;
}
