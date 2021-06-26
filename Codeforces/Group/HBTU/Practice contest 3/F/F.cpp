#include "bits/stdc++.h"
using namespace std;

const int maxn = 5e4 + 1;
vector<vector<int>> adj(maxn);
vector<int> ans(maxn , -1);

void dfs(int n , int p) {
	for(int& i : adj[n]) {
		if(i == p) continue;
		ans[i] = n;
		dfs(i , n);
	}
}

int main()
{
	int n , r1 , r2;
	scanf("%d %d %d" , &n , &r1 , &r2);
	for(int i = 1; i <= n; i++) {
		if(i == r1) continue;
		int x;
		scanf("%d" , &x);
		adj[i].emplace_back(x);
		adj[x].emplace_back(i);
	}
	dfs(r2 , -1);
	for(int i = 1; i <= n; i++) {
		if(i == r2) continue;
		printf("%d " , ans[i]);
	}
	return 0;
}