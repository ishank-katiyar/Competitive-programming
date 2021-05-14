#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , k;
	scanf("%d %d" , &n , &k);
	if(k == 0) {
		if(n == 1) puts("1");
		else puts("-1");
		return 0;
	}
	if(k < n / 2 || n == 1) {
		puts("-1");
		return 0;
	}
	int x = n / 2 - 1;
	k -= x;
	printf("%d %d " , k , 2 * k);
	for(int i = 1; i <= x; i++) {
		printf("%d %d " , 2 * k + 2 * i - 1, 2 * k + 2 * i);	
	}
	if(n & 1)  printf("%d" , 2 * k + 2 * x + 1);
	return 0;
}