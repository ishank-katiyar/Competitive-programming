#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int n;
	scanf("%I64d" , &n);
	long long int low = 1 , high = n;
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
		if(cnt1 >= (AN + 1)/ 2) return true;
		return false; 
	};
	while(low < high) {
		long long int mid = low + high;
		mid >>= 1;
		if(f(n , mid)) high = mid;
		else low = mid + 1;
	}             	
	printf("%I64d\n" , min(low , high));
	return 0;
}
