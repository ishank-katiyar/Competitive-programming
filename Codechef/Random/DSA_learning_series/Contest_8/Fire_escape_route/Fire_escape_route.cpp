#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

const int maxn = 100001;
vector<int> adj[maxn];
vector<bool> used(maxn);
long long int component_count;
const int mod = 1e9 + 7;

void dfs(int n) {
	used[n] = true;
	component_count++;
	for(int& i : adj[n]) {
	    if(used[i] == false) {
	    	dfs(i);
	    }
	}
}

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		for(int i = 0; i < maxn; i++)  adj[i].clear() , used[i] = false;
		int n , m;
		scanf("%d %d" , &n , &m);
		for(int i = 0; i < m; i++) {
			int x ,y;
			scanf("%d %d" , &x , &y);
			adj[x].emplace_back(y);
			adj[y].emplace_back(x);		
		} 
		for(int i = 1; i <= n; i++) debug(adj[i]);
		long long int ans = 1;
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(used[i] == false) {
				component_count = 0;
				dfs(i);
				cnt++;
				(ans *= component_count) %= mod;	
			}
		}
		for(int i = 1; i <= n; i++) debug(used[i]);
		printf("%d %I64d\n" , cnt , ans);
	}
	return 0;
}
