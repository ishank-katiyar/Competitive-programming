#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

long long int pow(long long int a , long long int b) {
	if(b == 0) return 1;
	long long int ret = 1;
	while(b) {
		if(b & 1) {
			ret *= (a % mod);
			ret %= mod;
		}
		a = (a % mod * a % mod);
		a %= mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	long long int a , b , n;
	scanf("%I64d %I64d %I64d" , &a , &b , &n);
	long long int x;
	scanf("%I64d" , &x);
	if(a == 1) {
		long long int ans = n % mod * b % mod;
		ans %= mod;
		ans += x % mod;
		ans %= mod;
		printf("%I64d" , ans);
		return 0;
	}
	long long int an = pow(a , n);
	long long int ans = an * x;
	ans %= mod;
	cerr << ans << '\n';
	ans += ((b % mod * (an - 1) % mod) % mod * pow((long long int)a - 1 , (long long int) mod - 2) % mod);
	ans %= mod;
	printf("%I64d" , ans);
	return 0;
}
