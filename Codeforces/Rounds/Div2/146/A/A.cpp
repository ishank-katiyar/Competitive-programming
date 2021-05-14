#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int n;
	scanf("%I64d" , &n);
	long long int ans = 1;
	if(n == 1) {
		puts("1");
		return 0;
	}
	if(n == 2) {
		puts("2");
		return 0;
	}

	if(n == 3) {
		puts("6");
		return 0;
	}
	ans = (n - 2 * (n % 6 < 1)) * (n - 1) * (n - 3 + n % 2);
	printf("%I64d" , ans);
	return 0;
}