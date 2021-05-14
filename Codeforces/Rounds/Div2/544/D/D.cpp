#include "bits/stdc++.h"
#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif
using namespace std;

int main()
{
	map<pair<int, int> , int> mp;
	int n;
	scanf("%d" , &n);
	vector<int> a(n) , b(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	for(int i = 0; i < n; i++) scanf("%d" , &b[i]);
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			cnt += (b[i] == 0);
			continue;
		}
		int sign = ((long long int)a[i] * b[i] > 0LL) ? 1 : -1;
		mp[{sign * abs(b[i] / __gcd(b[i] , a[i])) , abs(a[i] / __gcd(b[i] , a[i]))}]++;
	}
	int mx = 0;
	//debug(mp);
	pair<int , int> ap = {-1,-1};
	debug(ap);
	for(auto& i : mp) {
		debug(i.first); 
		mx = max(mx , i.second);
	}
	printf("%d" , cnt + mx);
	return 0;
}