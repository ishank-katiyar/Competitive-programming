#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	map<int, int> mp = {{8 , 4} , {15 , 8} , {16 , 15} , {23 , 16} , {42 , 23}};
	int cnt = 0;
	vector<int> c(100 , 0);
	for(int i = 0; i < n; i++) {
		if(a[i] == 4) c[4]++;
		if(mp.count(a[i])) {
			if(c[mp[a[i]]] > 0) {
				c[mp[a[i]]]--;
				c[a[i]]++;
			}
			else cnt++;
		}
		else cnt++;
	}
	cnt = n - c[42] * 6;
	assert((n - cnt) % 6 == 0);
	printf("%d" , cnt);
	return 0;
}

//4,8,15,16,23,42 