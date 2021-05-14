#include "bits/stdc++.h"
using namespace std;

int main()
{
	int a , b;
	scanf("%d %d" , &a , &b);
	int x = __gcd(a , b);
	set<int> factor;
	for(int j = 1; j <= (int) sqrt(x) ; j++) {
		if(x % j == 0) factor.insert(j) , factor.insert(x / j);
	}
	int q;
	scanf("%d" , &q);
	while(q--) {
		int l , r;
		scanf("%d %d" ,&l , &r);
		auto it = factor.lower_bound(r);
		if(it == factor.begin() && *it != r) {
			puts("-1");
			continue;
		}
		if(it == factor.end() || (int) *it != r) {
			it--;
			if((int) *it >= l && (int) *it <= r) {
				printf("%d\n" , (int) *it);
			}			
			else puts("-1");
		}           
		if((int) *it == r) printf("%d\n" , r);
	}
	return 0;
}
