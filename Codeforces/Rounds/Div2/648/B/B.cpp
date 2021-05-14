#include "bits/stdc++.h"
using namespace std;

bool sorted(vector<int> a) {
	vector<int> b(a);
	sort(b.begin() , b.end());
	return a == b;
}

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d" , &n);
		vector<int> a(n);
		for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d" , &x);
			if(x == 0) cnt++;
		}
		if(cnt == 0 || cnt == n) {
			puts(sorted(a) ? "Yes" : "No");
		}
		else puts("Yes");
	}
	return 0;
}
