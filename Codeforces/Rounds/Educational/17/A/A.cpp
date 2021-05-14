#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int n , k;
	scanf("%I64d %I64d" , &n , &k);
	if(k == 1) {
		puts("1");
		return 0;
	}
	k--;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i) continue;
		if(k == 1) {
			printf("%d" , i);
			return 0;
		} 
		if(n / i != i) k--;
	}
	for(int i = sqrt(n); i >= 2; i--) {
		if(n % i) continue;
		if(k == 1) {
			printf("%I64d" , (long long int)n / i);
			return 0;
		}
		k--;
	} 
	if(k == 1 && n != 1LL) {
		printf("%I64d" , n);
		return 0;
	}
	puts("-1");
	return 0;
}