#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e7 + 1;
vector<int> ar(maxn , 1);
vector<bool> is_prime(maxn , true);

int p(int n , int i) {
	int cnt = 0;
	while(n % i == 0) cnt++ , n /= i;
	return cnt;
}

void seive()
{
	ar[1] = 1;
	for(int i = 2; i < maxn; i++) {
		if(is_prime[i]) {
			ar[i] *= i;
			for(int j = 2 * i; j < maxn; j += i) {
				is_prime[j] = false;
				ar[j] *= (p(j , i) & 1 ? i : 1);
			}
		}
	}
}

int main()
{
	seive();
	int a , n;
	scanf("%d %d" , &a , &n);
	long long int ans = 0;
	for(int i = a; i <= a + n - 1; i++) ans += ar[i];
	printf("%I64d" , ans);
	return 0;
}
