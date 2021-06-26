#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	long long int sum = accumulate(a.begin() , a.end() , 0LL);
	if(sum % 3) {
		puts("0");
		return 0;
	}
	sum /= 3;
	vector<int> cnt(n);
	cnt[n - 1] = a[n -1] == sum;
	long long int suf = a[n - 1];
	for(int i = n - 2; i >= 0; i--) suf += a[i] , cnt[i] += cnt[i + 1] + (int) (suf == sum);
	long long int pref = 0;
	long long int ans = 0;
	for(int i = 0; i < n - 2; i++) {
		pref += a[i];
		if(pref == sum) {
			ans	+= cnt[i + 2];
		}
	}
	printf("%I64d" , ans);
	return 0;
}
