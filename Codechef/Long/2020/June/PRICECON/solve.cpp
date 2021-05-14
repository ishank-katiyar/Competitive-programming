#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n , k;
		scanf("%d %d" , &n , &k);
		int sum = 0;
		while(n--) {
			int x;
			scanf("%d" , &x);
			sum += max(0 , x - k); 
		}
		printf("%d\n" , sum);
	} 
	return 0;
}
