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
	for(int i = 0; i < n; i++) {
		if(a[i] >= c) {
			c++;
		}		
	}
	printf("%d" , c - 1);
	return 0;
}
