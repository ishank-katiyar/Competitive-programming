#include "bits/stdc++.h"
using namespace std;

int main()
{
	auto f = [](long long int N , long long int A) -> long long int{
		long long int T = N * (N + 1);
		T >>= 1;
		T -= (A - N);
		return T;	
	};
	int n , k;
	scanf("%d %d" , &n , &k);
	if(n == 1) {
		puts("0");
		return 0;
	}
	int low = 1 , high = n;
	while(low < high) {
		int mid = low + high;
		mid >>= 1;
		if(f(mid , n) > k) high = mid;
		if(f(mid , n) == k) {
			printf("%d" , n - mid);
			return 0;
		}
		if(f(mid , n) < k) low = mid + 1;
	}
	return 0;
}
