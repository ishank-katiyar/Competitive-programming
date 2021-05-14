#include "bits/stdc++.h"
using namespace std;

const int maxn = 1001;
vector<vector<int>> a(maxn , vector<int>(maxn));
int cnt;
int n , m;	
int x;

void dfs(int i , int j) {
	if(a[i][j] != x) return;
	a[i][j] = -1;
	cnt++;
	if(i + 1 < n) dfs(i + 1 , j);
	if(i > 0) dfs(i - 1 , j);
	if(j > 0) dfs(i , j - 1);
	if(j + 1 < m) dfs(i , j + 1);
}

int main()
{
	scanf("%d %d" , &n , &m);
	for(int i = 0; i < n; i++)  for(int j = 0; j < m; j++) scanf("%d" , &a[i][j]);
	int mx = 0, val = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] != -1) {
				x = a[i][j];
				cnt = 0;
				dfs(i , j);
				if(cnt > mx) {
					mx = cnt;
					val = x;
				}
				if(cnt == mx && x < val) val = x;
			}
		}
	}
	printf("%d %d" , val , mx);
	return 0;                           	
}