#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

vector<int> c(11 , 0);

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]) , c[a[i]]++;
	for(int i = n - 1; i >= 0; i--) {
		debug(c);
		set<int> s;
		multiset<int> q;
		for(int j = 1; j <= 10; j++) if(c[j]) s.insert(c[j]) , q.insert(c[j]);
		assert(s.empty() == false || q.empty() == false);
		if((int) s.size() > 2) {
			c[a[i]]--;
			continue;
		}
		if((int) q.size() == 1) {
			printf("%d" , i + 1);
			return 0;
		}
		if((int) s.size() == 1 && (int) *s.begin() == 1) {
			printf("%d" , i + 1);
			return 0;
		}
		if((int)*s.begin() == 1 && q.count(1) == 1) {
			printf("%d" , i + 1);
			return 0;
		}
		if((int)*(--s.end()) - (int)*s.begin() == 1 && q.count((int)*(--s.end())) == 1) {
			printf("%d" , i + 1);
			return 0;
		}
		c[a[i]]--;
	}		
	assert(false);
	return 0;
}
