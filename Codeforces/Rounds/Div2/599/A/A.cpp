#include "bits/stdc++.h"
using namespace std;

long long int sf(long long int n) {for(int i = 2; i <= sqrt(n); i++) if(n % i == 0) return i; return n;}

int main()
{
	long long int n;
	scanf("%I64d" , &n);
	if(n == 1) {
		puts("1");
		return 0;
	}
	long long int x = sf(n);
	while(n % x == 0) n /= x;
	printf("%I64d" , n == 1 ? x : 1);
	return 0;
}