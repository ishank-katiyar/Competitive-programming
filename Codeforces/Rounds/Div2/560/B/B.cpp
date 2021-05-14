#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	sort(a.begin() , a.end());
	int c = 1;
	int ans = 0;
	int index = 0;
	while(index < n) {
		if(a[index] >= c) {
			index++;
			c++;
			ans++;
		}
		else index++;
	}
	printf("%d" , ans);
	return 0;
}
