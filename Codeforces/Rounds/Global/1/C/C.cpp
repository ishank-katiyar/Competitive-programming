#include "bits/stdc++.h"
using namespace std;

int main()
{
	int q;
	scanf("%d" , &q);
	while(q--) {
		int n;
		scanf("%d" , &n);
		int ans = 1;
		while(ans <= n) ans *= 2;
		if(ans - 1 != n) printf("%d\n", ans - 1);
		else {
			ans = 1;
			for(int i = 2; i <= sqrt(n); i++) {
				if(n % i == 0) {
					ans = n / i;
					break;	
				}
			}
			printf("%d\n" , ans);
		}
	}
	return 0;
}