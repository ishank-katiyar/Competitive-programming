#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e6 + 1;
vector<vector<int>> pre_compute(maxn , vector<int>(10 , 0));

int g(int n) {
	if(n < 10) return n;
	int ret = 1;
	while(n) {
		if(n % 10) ret *= n % 10;
		n /= 10;
	}
	return g(ret);
}

int main()
{
	for(int i = 1; i < maxn ; i++) {
		int x = g(i);
		for(int j = 1; j <= 9; j++) {
			pre_compute[i][j] += pre_compute[i - 1][j] + (j == x);
		} 		
	}		
	int n;
	scanf("%d" , &n);
	while(n--) {
		int l , r , k;
		scanf("%d %d %d" , &l , &r , &k);
		printf("%d\n" , pre_compute[r][k] - pre_compute[l - 1][k]);
	}
	return 0;
}