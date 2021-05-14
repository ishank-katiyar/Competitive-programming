#include "bits/stdc++.h"
using namespace std;

const int maxa = 1e7 + 1;
vector<int> c(maxa , 0);
vector<bool> is_prime(maxa , true);
vector<int> cnt(maxa , 0);
vector<long long int> pref(maxa , 0);

void seive()
{
	for(int i = 2; i < maxa; i++) {
		if(is_prime[i]) {
			for(int j = i ; j < maxa; j += i) {
				if(j != i) is_prime[j] = false;
				cnt[i] += c[j];
			}
		}
	}
	pref[0] = pref[1] = 0;
	pref[2] = cnt[2];
	for(int i = 3; i < maxa; i++) pref[i] += pref[i - 1] + cnt[i];
}

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]) , c[a[i]]++;
	seive();
	int q;
	scanf("%d" , &q);
	while(q--) {
		int l,r;
		scanf("%d %d" , &l , &r);
		r = min(maxa - 1 , r);
		l = min(maxa - 1 , l);
		printf("%I64d\n" , pref[r] - pref[l - 1]);
	}
	return 0;			
}