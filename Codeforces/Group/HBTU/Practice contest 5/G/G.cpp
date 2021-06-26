#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int& i : a) scanf("%d" , &i);
	vector<pair<int , int>> q(n);
	q[0].first = 1;
	int cur = 1;
	for(int i = 1; i < n; i++) {
		if(a[i] > a[i - 1]) cur++;
		else cur = 1;
		q[i].first = cur;
	}
	cur = 1;
	q[n - 1].second = 1;
	for(int i = n - 2; i >= 0; i--) {
		if(a[i] < a[i + 1]) cur++;
		else cur = 1;
		q[i].second = cur;
	}
	debug(q);
	int ans = 1;
	for(int i = 0; i < n; i++) {
		if(i > 0 && i < n - 1) {
			if(a[i + 1] - a[i - 1] > 1) ans = max(ans , q[i - 1].first + q[i + 1].second + 1);
		}
		if(i > 0) ans = max(ans , q[i - 1].first + 1);
		if(i < n - 1)ans = max(ans , q[i + 1].second + 1);
	}
	printf("%d" , ans);
	return 0;
}