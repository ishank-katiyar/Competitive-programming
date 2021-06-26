#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

class comp {
	public:
		operator () (const pair<int , int> &a , const pair<int , int> &b) {
			if((a.second - a.first + 1) != (b.second - b.first + 1)) return (b.second - b.first + 1) > (a.second - a.first + 1);
			return b.first < a.first;
		}
};

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d" , &n);
		vector<int> a(n);
		priority_queue<pair<int , int> , vector<pair<int , int>> , comp> q;
		q.push(make_pair(1 , n));
		int c = 1;
		while(q.empty() == false) {
			debug(q);
			int l = q.top().first;
			int r = q.top().second;
			q.pop();
			int mid;
			if((r - l + 1) & 1) {
				mid = (l + r) / 2;
				a[((l + r) / 2) - 1] = c++;
			}	
			else a[((l + r - 1) / 2) - 1] = c++ , mid = (l + r - 1) / 2;
			mid--;
			if(l <= mid) q.push(make_pair(l , mid));
			mid += 2;
			if(mid <= r) q.push(make_pair(mid , r));
		}
		for(int& i : a) printf("%d " , i);
		puts("");
	}	
	return 0;
}