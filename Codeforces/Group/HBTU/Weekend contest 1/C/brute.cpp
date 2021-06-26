#include "bits/stdc++.h"
using namespace std;

int main()
{
	auto f = [](long long int N , long long int K) -> bool{
		long long int AN = N;
		long long int cnt1 = 0 , cnt2 = 0;
		while(N) {
			if(N <= K) {
				cnt1 += N , N = 0;
				break;
			}
			cnt1 += K;
			N -= K;
			cnt2 += (long long int)(N / 10);
			N -= (long long int)(N / 10);
		}
		if(cnt1 >= AN / 2) return true;
		return false; 
	};
	long long int n;
	scanf("%I64d" , &n);
	for(long long int i = 1; i <= n; i++) {
		if(f(n , i)) {
			printf("%I64d" , i);
			return 0;
		}
	}
	return 0;
}