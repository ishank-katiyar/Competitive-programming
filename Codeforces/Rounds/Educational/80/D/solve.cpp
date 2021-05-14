#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

const int maxn = 3e5 + 1;
vector<vector<int>> a(maxn , vector<int> (8 , 0));
int n , m;
int index1 = -1 , index2 = -1;

bool solve(int x) {
	map<int , int> c;
	for(int i = 0; i < n; i++) {
		int q = 0;
		for(int j = 0; j < m; j++) if(a[i][j] >= x) q |= (1 << j);
		c[q] = i;
	}
	for(int i = 0; i < (1 << m); i++) {
		for(int j = 0; j < (1 << m); j++) {
			if(((i | j) == (1 << m) - 1) && c.count(i) && c.count(j)) {
				index1 = c[i];
				index2 = c[j];
				return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d %d" , &n , &m);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d" , &a[i][j]);
	int low = 0 , high = 1e9;
	while(low < high) {
		int mid = low + high;
		mid >>= 1;
		if(solve(mid)) low = mid + 1;
		else high = mid;
	}
	low--;
	assert(solve(low));
	printf("%d %d" , index1 + 1 , index2 + 1);
	return 0;
}