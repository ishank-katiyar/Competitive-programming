#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	reverse(a.begin() , a.end());
	string s;
	cin >> s;
	reverse(s.begin() , s.end());
	vector<long long int>  suf(n);
	suf[n-1] = a[n-1];
	for(int i = n - 2; i >= 0; i--) suf[i] += suf[i+1] + a[i];
	long long int ans = 0;
	long long int sum = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			if(i != n - 1) ans = max(ans , sum + suf[i+1]);
			sum += a[i];
		}
	}
	ans = max(ans , sum);
	printf("%I64d" , ans);
	return 0;
}