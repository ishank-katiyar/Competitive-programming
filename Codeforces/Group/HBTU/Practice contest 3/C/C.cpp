#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int a , b , x , y;
	scanf("%I64d %I64d %I64d %I64d" , &a , &b, &x , &y);
	long long int gd = __gcd(x , y);
	x /= gd;
	y /= gd;
	printf("%I64d" , min((long long int)a / x , (long long int) b / y));
	return 0;  
}