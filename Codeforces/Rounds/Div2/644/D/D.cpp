#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n , k;
		scanf("%d %d" , &n , &k);
		if(k >= n) {
			puts("1");
			continue;
		}
		int ans = 1e9;
		for(int i = 2; i <= (int) sqrt(n); i++) {
			if(n % i == 0) {
				if(i <= k) {
					ans = min(ans  , n / i);
				}
				if((n / i) <= k) ans = min(ans , i);
			}
		}
		if(ans == 1e9) ans = n;
		printf("%d\n" , ans);
	}
	return 0;
}