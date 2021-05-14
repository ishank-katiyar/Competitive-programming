#include "bits/stdc++.h"
using namespace std;

int pow(int a , int b , int mod) {
	int ret = 1;
	while(b) {
		if(b & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	int p;
	scanf("%d" , &p);
	int cnt = 0;
	for(int x = 1; x < p; x++) {
		if(pow(x , p - 1, p) == 1) {
			bool flag = true;
			for(int pw = 1; pw <= p - 2; pw++) {
				if(pow(x , pw , p) == 1) {
					flag = false;
					break;
				}
			}	
			cnt += flag;
		}	
	}
	printf("%d",  cnt);
	return 0;
}