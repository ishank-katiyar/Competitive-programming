#include "bits/stdc++.h"
using namespace std;

int main()
{
	int a , b , c;
	scanf("%d %d %d" , &a , &b , &c);
	int t;
	if((a * c) % b) {
		t = (a * c) / b;
		t++;
	} 
	else t = (a * c) / b;
	printf("%d" , max(0 , t - c));
	return 0;
}
