#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

const int maxn = 1001;
vector<int> dis(maxn , 1e9);

void dfs(vector<vector<int>> &adj , int n , int p) {
	if((int) adj[n].size() == 1) {
		dis[n] = 0;
	}
	for(int& i : adj[n]) {
		if(i == p) continue;
		dfs(adj , i , n);
		dis[n] = min(dis[i] + 1, dis[n]);
	}	
}

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		dis.assign(maxn , 1e9);
		int n , x;
		scanf("%d %d" , &n , &x);
		vector<vector<int>> adj(n + 1);
		for(int i = 0 ; i < n - 1; i++) {
			int x1 , y1;
			scanf("%d %d" , &x1 , &y1);
			adj[x1].emplace_back(y1);
			adj[y1].emplace_back(x1);
		} 
		if(n == 1 || n == 2) {
			puts("Ayush");
			continue;
		}
		if((int) adj[x].size() == 1) {
			puts("Ayush");
			continue;
		}
		int rest = n - 2;
		puts(rest & 1 ? "Ashish" : "Ayush");
	}
	return 0;
}
