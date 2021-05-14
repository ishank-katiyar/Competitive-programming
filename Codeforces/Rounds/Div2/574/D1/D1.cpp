#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

const int mod = 998244353;

long long int pow(long long int a , int b){
	long long int ret = 1;
	while(b--) ret *= a;
	return ret;
} 

int main()
{
	int n;
	scanf("%d" , &n);
	debug(pow((long long int)10 , (int)18));
	long long int q1 = 1e18;
	debug(q1);
	vector<long long int> ar(n);
	for(int i = 0; i < n; i++) scanf("%I64d" , &ar[i]);
	long long int sum = 0;
	for(int i = 0; i < n; i++) {
		long long int x = 0;
		int pw = 0;
		while(ar[i]) {
			x += (ar[i] % 10) * pow(10 , pw) , pw += 2 , ar[i] /= 10;
			debug(x);
		}
		ar[i] = x;
		(sum += x) %= mod;
	}
	debug(ar , sum);
	long long int ans = 0;
	for(int i = 0; i < n; i++) {
		long long int cur = ar[i];
		cur %= mod;
		cur *= 10;
		cur %= mod;
		cur *= n;
		cur %= mod;
		cur += sum;
		cur %= mod;
		(ans += cur) %= mod;
	}
	printf("%I64d" , ans);
	return 0;
}


/*
111
222

121212 
212121
111111
222222
------
666666

101010
010101
202020
020202
1st base -> 303030
2nd base -> 030303

232323
434343
------
666666

*/