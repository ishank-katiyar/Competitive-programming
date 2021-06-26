#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

int main()
{
	int n , m;
	scanf("%d %d" , &n , &m);
	vector<long long int> a(n + 1 , 0);
	vector<long long int> aa(n);
	for(int i = 0; i < n; i++) {
		long long int x;
		scanf("%I64d" , &x);
		aa[i] = x;
		a[i + 1] += a[i] + aa[i]; 
	}
	debug(a);
	for(int i = 0; i < m; i++) {
		long long int b;
		scanf("%I64d" , &b);
		auto it = upper_bound(a.begin() , a.end() , b);
		assert(it != a.begin());
		int ind = (int) (it - a.begin());
		it--;
		if((long long int)*it == b) {
			ind--;
			printf("%d %I64d\n" , ind  , aa[ind -1]);
		}
		else printf("%d %I64d\n" , ind , b - (long long int)*it);
	} 
	return 0;
}
