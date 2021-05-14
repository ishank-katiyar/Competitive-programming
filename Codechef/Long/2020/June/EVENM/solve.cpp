#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d" , &n);
		vector<vector<int>> a(n , vector<int>(n , 0));
		int c = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) a[i - 1][j - 1] = c++;
			if(i % 2 == 0 && n % 2 == 0) {
				rotate(a[i - 1].begin() , a[i - 1].begin() + 1 , a[i - 1].end());
			}  
		}
		for(auto& i : a) {
			for(auto& j : i) printf("%d " , j);
			puts("");
		}
	}
	return 0;
}