#include "bits/stdc++.h"
using namespace std;

const int maxa = 1e5 + 1;
vector<int> c(maxa);

int main()
{
	int n;
	scanf("%d" , &n);
	for(int i = 0; i < maxa; i++)  c[i] = 0;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d" , &x);
		c[x]++;	
	}
	int ans = 1;
	for(int i = 2; i < maxa; i++) {
		int cur = 0;
		for(int j = i; j < maxa; j += i) cur += c[j];
		ans = max(ans , cur);
	}
	printf("%d" , ans);
	return 0;
}