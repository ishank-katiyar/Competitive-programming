#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for(int i = 0; i < n; i++)  scanf("%d" , &a[i]);
		sort(a.begin() , a.end());
		int ans = 1e9;
		for(int i = 1; i < n; i++) ans = min(ans , a[i] - a[i-1]);
		printf("%d\n" , ans);
	}
	return 0;
}