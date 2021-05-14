#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0 ; i < n; i++)  cin >> a[i];
	for(int i = 0 ; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 'S') {
				if(i > 0) {
					if(a[i - 1][j] == 'W') {
						puts("No");
						return 0;
					}
					if(a[i - 1][j] == '.') a[i - 1][j] = 'D';
				}
				if(i < n - 1) {
					if(a[i + 1][j] == 'W') {
						puts("No");
						return 0;
					}
					a[i + 1][j] = (a[i + 1][j] == '.' ? 'D' : a[i + 1][j]);
				}
				if(j > 0) {
					if(a[i][j - 1] == 'W') {
						puts("No");
						return 0;
					}
					if(a[i][j - 1] == '.') a[i][j - 1] = 'D';
				}
				if(j < m - 1) {
					if(a[i][j + 1] == 'W') {
						puts("No");
						return 0;
					}
					if(a[i][j + 1] == '.') a[i][j + 1] = 'D';
				}
			}
		}
	}
	puts("Yes");
	for(auto& i : a) printf("%s\n" , i.c_str());
	return 0;
}

