#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e5 + 1;
const int maxk = 101;
vector<vector<int>> adj(maxn);
vector<vector<int>> index(maxk);
vector<vector<int>> dis(maxn , vector<int>(maxk , 1e9));

int main()
{
	int n , m , k , s;
	scanf("%d %d %d %d" , &n , &m , &k , &s);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d" , &x);
		index[x].emplace_back(i + 1); 
	}
	for(int i = 0; i < m ; i++) {
		int x , y;
		scanf("%d %d" , &x , &y);
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	for(int i = 1; i <= k ; i++) {
		queue<int> q;
		//vector<int> dis(n + 1 , 1e9);
		vector<bool> used(n + 1 , false);
		for(int& j : index[i]) q.push(j) , used[j] = true , dis[j][i] = 0;
		while(!q.empty())  {
			int v = q.front();
			q.pop();
			for(int& u : adj[v]) {
				if(used[u] == false) {
					q.push(u);
					used[u] = true;
					dis[u][i] = min(dis[u][i] , dis[v][i] + 1);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		sort(dis[i].begin() , dis[i].end());
		long long int ans = 0;
		for(int j = 0; j < s; j++) {
			assert(dis[i][j] != 1e9);
			ans += dis[i][j];
		}
		printf("%I64d " , ans);
	} 
	return 0;
}
