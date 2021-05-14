#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d" , &n);
		vector<int> o,e;
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d" , &x);
			if(x & 1) o.emplace_back(x);
			else e.emplace_back(x);
		}  
		if((int) o.size() % 2 == 0) {
			puts("YES");
			continue;
		}
		map<int, int> mp;
		for(int &i : o) mp[i]++;
		bool flag = false;
		for(int& i : e) {
			if(mp.count(i + 1) || mp.count(i - 1)) {
				flag = true;
				break;
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}