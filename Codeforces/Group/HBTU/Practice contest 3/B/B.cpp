#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	long long int sum = accumulate(a.begin() , a.end() , 0LL);
	sort(a.begin() , a.end());
	int q;
	scanf("%d" , &q);
	while(q--) {
		int x;
		scanf("%d" , &x);
		printf("%I64d\n" , sum - a[n - x]);
	}
	return 0;
}