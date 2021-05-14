#include "bits/stdc++.h"
using namespace std;

const int maxn = 	1e3 + 1;
vector<vector<int>> adj(maxn);
bool flag = false;
vector<bool> used(maxn , false);
int s;

void dfs(int n) {
	if(used[n] == true)  return;
	cerr << n << '\n';
	flag |= (n == s);
	used[n] = true;
	for(int& i : adj[n]) dfs(i);
}


int main()
{
	int n;
	scanf("%d %d" , &n , &s);
	int prev = -1;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d" , &x);
		if(x == 1) {
			if(prev == -1) prev = i;
			else adj[prev].emplace_back(i) , prev = i;
		}
	}
	prev = -1;	
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d" , &x);
		if(x == 1) {
			if(prev == -1) prev = i;
			else adj[i].emplace_back(prev) , prev = i;
		}
	}
	dfs(1);
	puts(flag ? "YES" : "NO");
	return 0;
}
