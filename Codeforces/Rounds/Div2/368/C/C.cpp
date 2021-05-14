#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int n;
	scanf("%I64d" , &n);
	if(n <= 2) puts("-1");
	else {
		long long int x1;
		long long int x2;
		if(n & 1) {
			x1 = (long long int)n * n - 1;
			x2 = (long long int)n * n + 1;
			x1 /= 2;
			x2 /= 2;
		}
		else {
			x1 = (long long int)(n * n) / 4;
			x1--;
			x2 = (long long int)(n * n) / 4;
			x2++;
		}
		printf("%I64d %I64d" , x1 , x2);
	}
	return 0;
}