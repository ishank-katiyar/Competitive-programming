#include "bits/stdc++.h"
using namespace std;

const int maxn = 5e6 + 1;
vector<bool> is_prime(maxn , true);
vector<int> cnt_prime(maxn , 0);
vector<int> pref(maxn , 0);

void seive()
{
	auto f = [](int J , int I) -> int {
		int cnt = 0;
		while(J % I == 0) cnt++ , J /= I;
		return cnt;
	};
	for(int i = 2; i < maxn; i++) {
		if(is_prime[i]) {
			for(int j = i; j < maxn; j += i) {
				if(j != i) is_prime[j] = false;
				cnt_prime[j] += f(j , i);
			}
		}
	}
	pref[0] = pref[1] = 0;
	pref[2] = cnt_prime[2];
	for(int i = 3; i < maxn; i++) pref[i] += pref[i - 1] + cnt_prime[i];
}



int main()
{
	seive();
	for(int i = 0; i < 10; i++) cerr << cnt_prime[i] << ' ';
	cerr << '\n';
	for(int i = 0; i < 10; i++) cerr << pref[i] << ' ';
	cerr << '\n';	
	int t;
	scanf("%d" , &t);
	while(t--) {
		int a , b;
		scanf("%d  %d" , &a , &b);
		printf("%d\n" , pref[a] - pref[b]);
	}
	return 0;
}