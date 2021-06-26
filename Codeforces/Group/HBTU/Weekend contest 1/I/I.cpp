#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , k;
	scanf("%d %d" , &n , &k);
	k = 240 - k;
	int cnt = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += 5 * i;
		if(sum > k) break;
		cnt++;
	}
	printf("%d" , cnt);
	return 0;
}

