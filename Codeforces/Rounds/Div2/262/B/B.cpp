#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL 
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

long long int pow(long long int a, long long int b) {
	long long int ret = 1;
	while(b--) ret *= a;
	return ret;
}

int main()
{
	long long int a, b, c;
	scanf("%I64d %I64d %I64d" , &a , &b , &c);
	vector<int> ans;
	for(int i = 1; i <= 81; i++) {
		long long int n = pow((long long int)i , a);
		n *= b;
		n += c;
		long long int an = n;
		int sum = 0;
		while(n) sum += n % 10 , n /= 10;
		if(sum == i && an < (long long int)1e9) ans.emplace_back(an);
	}
	printf("%d\n" , (int) ans.size());
	for(int& i : ans) printf("%d " , i);
	return 0;
}