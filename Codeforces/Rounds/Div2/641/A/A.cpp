#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

const int maxa = 2e5 + 1;
vector<int> c(maxa , 0);
vector<multiset<int>> c1(maxa);

long long int pow(int a , int b) {
	long long int ret = 1;
	while(b--) ret *= (long long int) a;
	return ret;
}

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	for(int i = 0 ; i < n; i++) {
		int x = a[i];
		for(int j = 2; j <= (int) sqrt(x); j++) {
			if(x % j) continue;
			int cnt = 0;
			c[j]++;
			while(x % j == 0) cnt++ , x /= j;
			c1[j].insert(cnt);
			if((int) c1[j].size() > 2) c1[j].erase(--c1[j].end());
		}
		if(x != 1) {
			c[x]++;
			c1[x].insert(1);
			if((int) c1[x].size() > 2) c1[x].erase(--c1[x].end());
		}
	}
	long long int ans = 1;
	set<int> all;
	for(int i = 2; i < maxa; i++) {
		all.insert(c[i]);
		if(c[i] == n) {
			debug(i,c1[i]);
			ans *= pow(i , (int) *(--c1[i].end()));
		}
		if(c[i] == n - 1) {
			debug(i,c1[i]);
			ans *= pow(i , (int) *c1[i].begin());
		}
	}
	debug(all);
	printf("%I64d" , ans);
	return 0;
}