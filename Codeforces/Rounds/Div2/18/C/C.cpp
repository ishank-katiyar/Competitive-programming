#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	int sum = 0; 
	for(int& i : a) scanf("%d" , &i) , sum += i;
	if(sum % 2) {
		puts("0");
		return 0;
	}
	sum >>= 1;
	int sum1 = 0;
	int ways = 0;
	for(int i = 0; i < n - 1; i++) {
		sum1 += a[i];
		if(sum1 == sum)  ways++;
	}	 
	printf("%d" , ways);
	return 0;
}
