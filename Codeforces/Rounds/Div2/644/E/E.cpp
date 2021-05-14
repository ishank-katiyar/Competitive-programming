#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d" , &n);
		vector<string> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		bool flag = true; 
		for(int i = 0; i < n - 1; i++) {
			for(int j = 0 ; j < n - 1; j++) {
				if(a[i][j] == '1' && a[i+1][j] == '0' && a[i][j+1] == '0') {
					flag = false;
					break;
				}		
			}	
			if(flag == false) break;
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}