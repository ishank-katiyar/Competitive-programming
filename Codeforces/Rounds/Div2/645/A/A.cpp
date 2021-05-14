#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n ,m;
		scanf("%d %d" , &n , &m);
		int ans = 0;
		if(n % 2 == 0 || m % 2 == 0)  ans = (n * m) / 2;
		else {
			if(n > m) swap(n,m);
			ans += n / 2 + 1;
			ans += n * (m / 2);
		}
		printf("%d\n" , ans);
	}
	return 0;
}