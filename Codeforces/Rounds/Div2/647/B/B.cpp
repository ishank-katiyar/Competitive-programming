#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d" , &n);
		multiset<int> s;
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d" , &x);
			s.insert(x);
		}
		int ans = -1;
		for(int j = 1; j <= 1024; j++) {
			multiset<int> b;
			for(int i : s) b.insert(i ^ j);
			if(s == b) {
				ans = j;
				break;
			}
		}
		if(ans == -1) puts("-1");
		else printf("%d\n" , ans);
	}
	return 0;
}
