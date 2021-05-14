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
		int cnt = 0;
		int n = (int) s.size();
		for(int i = 1; i < n; i++) {
			if((s[i] == 'x' && s[i - 1] == 'y') || (s[i] == 'y' && s[i - 1] == 'x')) {
				cnt++;
				i++;
			}		
		}
		cout << cnt << '\n';
	}
	return 0;
}
