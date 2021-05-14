#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

const int maxn = 50;
const int maxm = 50;
int b = 0 , g = 0;
int n , m;
vector<vector<bool>> used(maxn , vector<bool>(maxm , false));

void dfs(int r , int c , vector<string> &a) {
  if(used[r][c] == true) return;
  used[r][c] = true;
  if(a[r][c] == '#') return;
	if(a[r][c] == 'G') g++;
	if(a[r][c] == 'B') b++;
	if(r - 1 >= 0) dfs(r - 1 , c , a);
	if(r + 1 < n) dfs(r + 1 , c , a);
	if(c - 1 >= 0) dfs(r , c - 1 , a);
	if(c + 1 < m) dfs(r , c + 1 , a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		vector<string> a(n);
		int gg = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			for(char& j : a[i]) if(j == 'G') gg++;
		}
		debug(a , gg);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] == 'B') {
					if(i - 1 >= 0 && a[i - 1][j] == '.') a[i - 1][j] = '#';
					if(i + 1 < n && a[i + 1][j] == '.') a[i + 1][j] = '#';   
					if(j - 1 >= 0 && a[i][j - 1] == '.') a[i][j - 1] = '#';
					if(j + 1 < m && a[i][j + 1] == '.') a[i][j + 1] = '#';
				}
			}
		}
		debug(a);
		b = 0;
		g = 0;
		for(int i = 0; i < maxn; i++) {
			for(int j = 0; j < maxm; j++) used[i][j] = false;
		}
		dfs(n - 1 , m - 1 , a);
		debug(b , g);
		if(b == 0 && g == gg) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
