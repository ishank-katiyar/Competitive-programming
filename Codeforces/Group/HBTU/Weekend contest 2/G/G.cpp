#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...)
#endif

int main()
{
	int n , q;
	scanf("%d %d" , &n , &q);
	vector<int> ar(n);
	deque<int> d;
	for(int& i : ar) scanf("%d" , &i) , d.push_back(i);
	int mx = (int) *max_element(ar.begin() , ar.end());
	vector<pair<int, int>> query(n + 1);	
	int c = 1;	
	while(1) {
		int a = d.front();
		if(a == mx) break;
		d.pop_front();
		int b = d.front();
		d.pop_front();
		query[c] = make_pair(a , b);
		c++;
		d.push_front(max(a , b));
		d.push_back(min(a , b));
		debug(d);
	}
	debug(c);
	c--;
	ar.clear();
	for(int i : d) ar.emplace_back(i);
	query[n] = {ar[0] , ar[1]};
	debug(ar);
	while(q--) {
		__int64 x;
		scanf("%I64d" , &x);
		if(x <= c) {
			printf("%d %d\n" , query[x].first , query[x].second);	
		}	
		else {
			printf("%d " , mx);
			x -= c;
			debug(x);
			x %= (n - 1);
			if(x == 0) x = n - 1;
			printf("%d\n" , ar[x]);		
		}
	}
	return 0;
}