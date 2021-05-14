#include "bits/stdc++.h"
#ifdef LOCAL	
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif
using namespace std;

vector<long long int> prime(long long int n) {
	vector<long long int > ret;
	long long int  an = n;
	for(int i = 2; i <= sqrt(an); i++) {
		if(n % i) continue;
		while(n % i == 0) n /= i , ret.emplace_back(i);
	}  
	if(n != 1) ret.emplace_back(n);
	return ret;
}

int main()
{
	long long int x;
	scanf("%I64d" , &x);
	if(x == 1) {
		puts("1\n0");
		return 0;
	}
	vector<long long int> fact = prime(x);
	debug(fact);
	if((int) fact.size() == 1) {
		puts("1\n0");
		return 0;
	}
	if((int) fact.size() == 2) {
		puts("2");
		return 0;
	}
	puts("1");
	printf("%I64d" , (long long int) (fact[0] * fact[1]));
	return 0;
}