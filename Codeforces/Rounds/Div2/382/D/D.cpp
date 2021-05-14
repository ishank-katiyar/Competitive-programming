#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...)
#endif
                
bool is_prime(int n) {
	if(n == 1) return false;
	for(int i = 2; i <= (int) sqrt(n); i++) if(n % i == 0) return false;
	return true;
}

int main()
{
	int n;
	scanf("%d" , &n);
	if(is_prime(n)) {
		puts("1");
		return 0; 
	}
	if(is_prime(n - 2)) {
		puts("2");
		return 0;
	} 
	printf("%d" , n & 1 ? 3 : 2);
	return 0;
}