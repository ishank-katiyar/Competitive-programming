#include "bits/stdc++.h"
using namespace std;

int p(__int64 n) {
	int ret = -1;
	while(n) ret++ , n /= 2;
	return ret;
}

int main()
{
	int tt;
	scanf("%d" , &tt);
	while(tt--) {
		__int64 a , b;
		scanf("%I64d %I64d" , &a , &b);
		__int64 t;
		if(a >= b)  {
			if(a % b) {
				puts("-1");
				continue;
			}
			else t = a / b;
		}
		else {
			if(b % a) {
				puts("-1");
				continue;
			}
			else t = b / a;
		}
		if(t && !(t & (t - 1))) {
			int pw = p(t);
			int ans = 0;
			ans += pw / 3;
			pw %= 3;
			ans += pw / 2;
			pw %= 2;
			ans += pw / 1;
			printf("%d\n" , ans);	
		}
		else puts("-1");
	}
	return 0;
}
