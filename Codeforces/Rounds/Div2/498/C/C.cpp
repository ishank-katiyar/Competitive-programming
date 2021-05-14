#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	set<__int64> s;
	vector<int> a(n);
	for(int& i : a) scanf("%d" , &i);
	__int64 sum = 0;
	for(int i = n - 1; i >= 0; i--) {
		sum += a[i];
		s.insert(sum);
	} 
	__int64 ans = 0;
	sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		s.erase(--s.end());
		if(s.count(sum)) ans = sum;
	}
	printf("%I64d" , ans);
	return 0;
}
