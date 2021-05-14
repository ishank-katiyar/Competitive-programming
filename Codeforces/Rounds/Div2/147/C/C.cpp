#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e6 + 1;
vector<bool> is_prime(maxn , true);
vector<int> prime;

void seive()
{
	is_prime[1] = false;
	for(int i = 2; i < maxn; i++) {
		if(is_prime[i]) {
			prime.emplace_back(i);
			for(long long int j = (long long int)i * i; j < maxn; j += i) is_prime[j] = false;
		}
	}
}

int main()
{
	seive();
	int a , b , k;
	scanf("%d %d %d" , &a , &b , &k);
	int cnt = 0;
	for(int i = a; i <= b; i++) if(is_prime[i]) cnt++;
	if(cnt < k) puts("-1");
	else {
		vector<int> prime1;
		int cnt = 0;
		int mx = 0;
		for(int i = a; i <= b; i++) {
			if(is_prime[i] == true) {
				cnt++;
				prime1.emplace_back(i);
			}
			if(cnt >= k) {
				mx = max(mx , i - prime1[cnt - k] + 1);	
			}
		}
		cnt = 0;
		vector<int> prime2;
		for(int i = b; i >= a; i--) {
			if(is_prime[i] == true) {
				cnt++;
				prime2.emplace_back(i);
			}
			if(cnt >= k) {
				mx = max(mx , prime2[cnt - k] - i + 1);
			}
		}
		printf("%d" , mx);
	}
	return 0;
}