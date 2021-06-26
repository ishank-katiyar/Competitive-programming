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
		int x0 , y0;
		scanf("%d %d" , &x0 , &y0);
		int k;
		scanf("%d" , &k);
		__int64 sum = 0;
		while(k--) {
			int x1 , y1;
			scanf("%d %d" , &x1 , &y1);
			if(x1 == 0 && y1 == 0) {
				continue;
			}
			int q1 = 1e9, q2 = 1e9;
			if(x1 > 0) {
				int x = n - x0;
				q1 = x / x1;
			}
			else if(x1 < 0){
				int x = x0 - 1;
				q1 = x / x1;
			}
			if(y1 > 0) {
				int y = m - y0;
				q2 = y / y1;
			} 
			else if(y1 < 0){
				int y = y0 - 1;
				q2 = y / y1;
			}
			if(q1 < 0) q1 *= -1;
			if(q2 < 0) q2 *= -1;
			sum += abs(min(q1 , q2));
			x0 += min(q1 , q2) * x1;
			y0 += min(q1 , q2) * y1;
			debug(q1 , q2 , x0 , y0);
		}
		printf("%I64d" , sum);
		return 0;
}
