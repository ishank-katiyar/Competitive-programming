#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

int main()
{
	int l , r , x , y;
	scanf("%d %d %d %d" , &l , &r , &x , &y);
	int cnt = 0;
	if(y % x) puts("0");
	else {
		y /= x;
		auto check = [](int L , int R , int i) -> bool {
		  	return i >= L && i <= R;
		};
		for(int i = 1; i <= (int) sqrt(y) ; i++) {
			if(y % i) continue;
			if(check(l , r , i * x) && check(l , r , (y / i) * x) && __gcd(i , y / i) == 1) cnt += 1 + (int)(i != y / i);
		}
		printf("%d" , cnt);
	}
	return 0;
}