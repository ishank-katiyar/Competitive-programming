#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int u , v;
	scanf("%I64d %I64d" , &u , &v);
	if(u == v && u == 0) puts("0");
	else if(u == v && u != 0) printf("1\n%I64d" , u);
	else if(u > v || (u % 2) != (v % 2)) puts("-1");
	else {
		long long int x = v - u;
		x >>= 1;
		if(x & u) {
			printf("3\n%I64d %I64d %I64d" , u , x , x);
		}
		else {
			printf("2\n%I64d %I64d" , u + x , x);
		}
	}
	return 0;
}