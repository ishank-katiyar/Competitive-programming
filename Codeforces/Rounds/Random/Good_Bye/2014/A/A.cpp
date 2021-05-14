#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , t;
	scanf("%d %d" , &n , &t);
	vector<int> a(n);
	for(int i = 1; i < n; i++) scanf("%d" ,&a[i]);
	bool ok = false;
	int index = 1;
	while(index < n) {
		ok |= (index == t);
		index += a[index];
	}
	ok |= (index == t);
	puts(ok ? "YES" : "NO");
	return 0;
}
