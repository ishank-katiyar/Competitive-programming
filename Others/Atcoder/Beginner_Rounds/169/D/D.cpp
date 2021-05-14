#include "bits/stdc++.h"
using namespace std;

int f(int x) {
	int c = 1;
	int sum = 0;
	int ret = 0;
	while(sum <= x) {
		sum += c;
		c++;
	}
	c--;
	return c - 1;
}

int main()
{ 
	printf("%d\n" , f(6));
	printf("%d\n" , f(5));
	printf("%d\n" , f(7));
	long long int n;
	scanf("%I64d" , &n);
	int ans = 0;
	for(int j = 2; j <= (int) sqrt(n); j++) {
		if(n % j) continue;
		int cnt = 0;
		while(n % j == 0) cnt++ , n /= j;
		ans += f(cnt);
	}
	if(n != 1) ans++;
	printf("%d" , ans);
	return 0;
}

