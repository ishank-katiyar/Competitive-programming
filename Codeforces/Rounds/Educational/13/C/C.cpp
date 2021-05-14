#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include"personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

int main()
{
	long long int n , a , b , p , q;
	scanf("%I64d %I64d %I64d %I64d %I64d"  , &n , &a , &b , &p , &q);
	long long int q1 = a * b / __gcd(a , b);
	long long int cnt = (n - (n % q1)) - q1;
	cnt /= q1;
	cnt++;
	debug(cnt);
	long long int ans = 0;
	ans += cnt * max(p , q);
	long long int cnt1 = (n - (n % a)) - a;
	cnt1 /= a;
	cnt1++;
	cnt1 -= cnt;
	ans += cnt1 * p;
	debug(cnt1);
	cnt1 = (n - n % b) - b;
	cnt1 /= b;
	cnt1++;
	cnt1 -= cnt;
	debug(cnt1);
	ans += cnt1 * q;
	printf("%I64d" , ans);
	return 0;  	
}