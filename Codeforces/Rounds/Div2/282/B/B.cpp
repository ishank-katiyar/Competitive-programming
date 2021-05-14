#include "bits/stdc++.h"
using namespace std;

int main()
{
	int a , b;
	scanf("%d %d" , &a , &b);
	if(a == b) puts("infinity");
	else if(b > a) puts("0");
	else {
		int cnt = 0;
		for(int i = 1; i <= (int) sqrt(a - b); i++) {
			if((a - b) % i) continue;
			if(i >= b && a % i == b) cnt++;
			if((a - b) / i != i && (a - b) / i >= b && a % ((a - b) / i) == b) cnt++; 	
		}
		printf("%d" , cnt);
	}
	return 0;
}