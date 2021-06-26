#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<string> a(n);
	for(int i = 0; i < n; i++) 	cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == '.') {
				if((i == 0 && j == 0) || (i >= n-2 || j == n-1) || (j == 0)) {
					puts("NO");
					return 0;
				}
				if(a[i][j]  == '.' && a[i+1][j] == '.' && a[i+2][j] == '.' && a[i+1][j-1] == '.' && a[i+1][j+1] == '.') {
					a[i][j] = '#';
					a[i+1][j] = '#';
					a[i+2][j] = '#';
					a[i+1][j-1] = '#';
					a[i+1][j+1] = '#';
				}
				else {
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
	return 0;
}