#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = (int) s.size();
		int ans = 1e9;
		int x = 0 , y = 0;
		int t0 = count(s.begin() , s.end() , '0');
		int t1 = n - t0;
		for(int i = 0; i < n; i++)  {
			if(s[i] == '0') x++;
			else y++;
			ans = min(ans , y + n - t1 - x);
			ans = min(ans , x + n - t0 - y);	
		}
		cout << ans << '\n';
	}
	return 0;
}
