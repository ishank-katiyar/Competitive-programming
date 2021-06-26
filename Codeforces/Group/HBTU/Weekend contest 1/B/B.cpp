#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int s , i , f;
		scanf("%d %d %d" , &s , &i , &f);
		if(s + f <= i) {
			puts("0");
			continue;
		}
		int maxs = s + f;
		int total = s + f + i;
		int low = i;
		int high = s + f;
		while(low < high) {
			int mid = low + high;
			mid >>= 1;
			if(mid > (total - mid)) high = mid;
			else low = mid + 1;
		}
		int mins = max(low , s);
		//debug(maxs,mins,high);
		printf("%d\n" , maxs - mins + 1);
	}
	return 0;
}