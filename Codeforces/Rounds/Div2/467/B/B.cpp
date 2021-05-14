#include "bits/stdc++.h"
using namespace std;

int sf(int n) {for(int i = 2; i * i <= n; i++) if(n % i == 0) return i;  return n;}

int main()
{
	int p , y;
	scanf("%d %d" , &p , &y);
	while(1) {
	    if(y == p) break;
	    if(sf(y) > p) {
	    	printf("%d" , y);
	    	return 0;
	    }	
	    y--;
	}
	puts("-1");
	return 0;
}