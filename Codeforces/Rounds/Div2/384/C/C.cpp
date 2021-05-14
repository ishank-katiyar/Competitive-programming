#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	if(n == 1) {
		puts("-1");
		return 0;
	}
	for(int i = n + 1; i <= (int)INT_MAX; i++) {
		long long int x = n * i;
		if(x % (i - n) == 0) {
			printf("%d %d %I64d" , n , i , (long long int) x / (i - n));
			return 0;
		} 	
	}
	assert(0);
	return 0;
}