#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	if(n <= 2) {
		puts("-1");
		return 0;
	}
	while(n--) printf("%d " , n + 1);
	return 0;
}
