#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int a , b;
	scanf("%I64d %I64d" , &a , &b);
	long long int cnt = 0;
	while(b) {
		cnt += a / b;
		a %= b;
		swap(a , b);
	}
	printf("%I64d" , cnt);
	return 0;
}