#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5 + 1;
vector<int> parent(maxn , -1);

int main()
{
	int n;
	scanf("%d" , &n);
	for(int i = 2; i <= n; i++) {
		int x;
		scanf("%d" , &x);
		parent[i] = x;
	} 
	vector<int> path;
	for(int u = n; u != -1; u = parent[u]) path.emplace_back(u);
	reverse(path.begin() , path.end());
	for(int& i : path) printf("%d " , i);
	return 0;
}
