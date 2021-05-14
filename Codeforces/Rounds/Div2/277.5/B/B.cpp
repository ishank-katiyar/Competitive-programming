#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);	
	int m;
	scanf("%d" , &m);
	vector<int> b(m);
	for(int i = 0; i < m; i++) scanf("%d" , &b[i]);
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());
	int cnt = 0;
	int i1 = 0 , i2 = 0; 
	while(i1 < n && i2 < m) {
		if(abs(a[i1] - b[i2]) <= 1) {
			cnt++;
			i1++;
			i2++;
		}
		else {
			if(a[i1] < b[i2]) i1++;
			else i2++;
		}
	}
	printf("%d" , cnt);
	return 0;
}
