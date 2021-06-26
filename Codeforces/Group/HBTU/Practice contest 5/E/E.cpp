#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	__int64 ans = 0;
	int cur = 1;
	int x;
	cin >> x;
	ans += cur;
	int prev = x;
	for(int i = 1; i < n; i++) {
		cin >> x;
		if(x == prev) cur++;
		else {
			cur = 1;	
		}
		ans += cur;
		prev = x;
	}
	printf("%I64d" , ans);
	return 0;
}
