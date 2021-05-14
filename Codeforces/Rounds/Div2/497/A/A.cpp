#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	multiset<int> s;
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]) , s.insert(a[i]);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		auto it = s.upper_bound(a[i]);
		if(it != s.end()) {
			ans++;
			s.erase(it);
		}
	}
	printf("%d" , ans);
	return 0;
}
