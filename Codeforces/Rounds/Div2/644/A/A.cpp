#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int a,b;
		scanf("%d %d" , &a , &b);
		int ans = min(max(2 * a , b) , max(2 * b , a));
		printf("%d\n" , ans * ans); 
	}
	return 0;
}