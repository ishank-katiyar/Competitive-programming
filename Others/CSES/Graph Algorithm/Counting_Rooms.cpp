#include <bits/stdc++.h>
using namespace std;

int n , m;

void dfs(int r , int c , vector<string> &a) {
	if(a[r][c] == '#') return;
	a[r][c] = '#';
	if(r + 1 < n) dfs(r+1 , c , a);
	if(r-1 >= 0) dfs(r - 1 , c , a);
	if(c + 1 < m) dfs(r , c + 1 , a);
	if(c - 1 >= 0) dfs(r , c - 1 , a);	
}

int main()
{
	cin >> n >> m;
	vector<string> ab(n);
	for(int i = 0; i < n; i++) cin >> ab[i];
	int cnt=0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
		if(ab[i][j] == '.') dfs(i , j , ab)  , cnt++;
	}  
	cout << cnt;
	return 0;
}
