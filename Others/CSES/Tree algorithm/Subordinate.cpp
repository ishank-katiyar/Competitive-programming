#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5 + 1;
vector<int> adj[maxn];
vector<int> dis(maxn);

void dfs(int n) {
	for(int& i : adj[n]) {
		dfs(i);
		dis[n] += dis[i] + 1;
	}	
}

int main()
{
	int n;
	scanf("%d" , &n);
	for(int i = 0; i < n - 1; i++) {
		int x;
		scanf("%d" , &x);
		adj[x].emplace_back(i + 2);
	} 
	dfs(1);
	for(int i = 1; i <= n; i++) printf("%d ", dis[i]);
	return 0;
}