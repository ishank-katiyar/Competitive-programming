#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int n;
	scanf("%I64d" , &n);
	long long int ans = 0;
	ans += n;
	ans += (n / 6);
	ans += (n / 10);
	ans += (n / 14);
	ans += (n / 15);
	ans += (n / 21);
	ans += (n / 35);
	ans += (n / 210);
	ans -= (n / 2);
	ans -= (n / 3);
	ans -= (n / 5);
	ans -= (n / 7);
	ans -= (n / 30);
	ans -= (n / 42);
	ans -= (n / 70);
	ans -= (n / 105);
	printf("%I64d" , ans);
	return 0;
}
