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
		map<int , int> mp;
		for(int i = 0; i < n; i++) scanf("%d" , &a[i]) , mp[a[i]]++;
		sort(a.begin() , a.end());
		long long int ans = (long long int) a[0] * a[n-1];
		int i = 0;
		int j = n - 1;
		bool flag = true;
		while(i <= j) {
			if((long long int)a[i] * a[j] != ans) {
				flag = false;
				break;
			}
			i++;
			j--;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 2; j <= (int) sqrt(a[i]); j++) {
				if(a[i] % j == 0) {
					if(mp.count(j) == 0 || mp.count(a[i] / j) == 0) flag = false; 
				}
			}
		}
		printf("%I64d\n" , flag ? ans : -1);
	}
	return 0;
}