#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d" , &n);
		vector<int> a(n);
		for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
		int mn = a[n - 1];
		int cnt = 0;
		for(int i = n - 2; i >= 0; i--) {
			if(a[i] > mn) cnt++;
			if(a[i] < mn) mn = a[i];
		}
		printf("%d\n" , cnt);
	}
	return 0;
}
