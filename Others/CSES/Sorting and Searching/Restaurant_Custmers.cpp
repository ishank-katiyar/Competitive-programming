#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> mp;
	int x , y;
	for(int i = 0;i < n; i++) cin >> x >> y , mp[x]++ , mp[y]--;
	int ans = 0;
	int cur = 0;
	for(auto& i : mp) {
		if(i.second == 1) cur++;
		else cur--;
		ans = max(ans , cur);
	} 
	cout << ans;
	return 0;
}

/*
1   2  3  4  5   7   9   10
+1 +1 +1 -1 -1  +1  -1  -1
*/