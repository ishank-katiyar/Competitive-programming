#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e3 + 1;
vector<vector<int>> adj(maxn);
vector<int> level(maxn , 0);
vector<bool> used(maxn , false);

int main()
{
	int n;
	scanf("%d" , &n);
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d" , &x);
		if(x == -1) q.push(i) , level[i] = 1 , used[i] = true;
		else adj[x].emplace_back(i) , adj[i].emplace_back(x);
	}

	while(q.empty() == false) {
		int v = q.front();
		q.pop();
		for(int& u : adj[v]) {
			if(used[u] == false) {
				q.push(u);
				used[u] = true;
				level[u] = level[v] + 1;
			}
		}
	}
	printf("%d" , (int) *max_element(level.begin() , level.end()));
	return 0;
}
