#include "bits/stdc++.h"
using namespace std;

const int maxn = 5e5 + 1;
vector<vector<int>> adj(maxn);  
vector<int> value(maxn , 1e9);
vector<vector<int>> v(maxn);

int mex(set<int> &s) {
	int n = (int) s.size();
	if(n == 0) return 1;
	if(*(--s.end()) == n) return n + 1; 
	for(int i = 1; i <= n; i++) {
		if(s.count(i) == 0) return i;
	}
	assert(false);
	return -1;
}

int main()
{
	int n , m;
	scanf("%d %d" , &n , &m);
	for(int i = 1; i <= m; i++) {
		int x , y;
		scanf("%d %d" , &x , &y);
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	for(int i = 1; i <= n; i++)  {
		int x;
		scanf("%d" , &x);
		v[x].emplace_back(i);
		value[i] = x;
	}	
	vector<int> ans;
	for(auto& i : v) {
		for(auto& j : i) ans.emplace_back(j);
	}
	bool ok = true;
	for(int i = 1; i <= n; i++) {
		set<int> vl;
		for(int& j : adj[i]) vl.insert(value[j]);
		ok &= (value[i] == mex(vl));
	}
	if(ok) {
		for(int& i : ans) printf("%d " , i);
	}
	else puts("-1");
	return 0;
}
