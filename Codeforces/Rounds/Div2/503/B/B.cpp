#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e3 + 1;
vector<int> edge(maxn , 0);
vector<bool> used(maxn , false);

int main()
{
	int n;
	scanf("%d" , &n);
	for(int i = 1; i <= n; i++) scanf("%d" , &edge[i]);
	for(int i = 1; i <= n; i++) {
		used.assign(maxn , false);
		for(int u = i ; ; u = edge[u]) {
			if(used[u]) {
				printf("%d " , u);
				break;
			}
			else used[u] = true;
		}
	}
	return 0;
}
