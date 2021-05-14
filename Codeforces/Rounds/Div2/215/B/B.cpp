#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , m;
	scanf("%d %d" , &n , &m);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	vector<int> ans(n);
	set<int> s;
	for(int i = n - 1; i >= 0; i--) {
		s.insert(a[i]);
		ans[i] = (int) s.size();
	}
	while(m--) {
		int x;
		scanf("%d" , &x);
		printf("%d\n" , ans[x - 1]);
	}
	return 0;
}
