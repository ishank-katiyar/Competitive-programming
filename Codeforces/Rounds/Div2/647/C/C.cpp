#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		__int64 n;
		scanf("%I64d" , &n);
		__int64 ans = 0;
		while(n) ans += n , n /= 2;
		printf("%I64d\n" , ans);
	}
	return 0;
}
