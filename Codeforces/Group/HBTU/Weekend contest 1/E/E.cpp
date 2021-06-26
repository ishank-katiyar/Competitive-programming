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
		int ans = 1;
		int i = 0;
		while(i < n) {
			if(s[i] == 'L') {
				int cur = 0;
				while(i < n && s[i] == 'L') cur++ , i++;
				ans = max(ans , cur + 1);
			}
			else i++;
		}
		cout << ans << '\n';
	}
	return 0;
}
