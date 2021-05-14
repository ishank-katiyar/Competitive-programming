#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e5 + 1;
vector<int> r(maxn , 0);
vector<int> c(maxn , 0);

int main()
{
	int n , m;
	scanf("%d %d" , &n , &m);
	__int64 total = (__int64) n * n;
	__int64 sum = 0;
	set<int> row;
	set<int> col;
	while(m--) {
		int x , y;
		scanf("%d %d" , &x , &y);
		__int64 add = 0;
		int ok = 0;
		if(r[x] == 0) {
			ok++;
			int csz = (int) col.size();
			add += (__int64) (n - csz);
		}	
		if(c[y] == 0) {
			ok++;
			int rsz = (int) row.size();
			add += (__int64) (n - rsz);
		}
		sum += add - (int) (ok == 2);
		row.insert(x);
		col.insert(y);
		r[x]++;
		c[y]++;
		printf("%I64d	" , total - sum);
	}
	return 0;
}
