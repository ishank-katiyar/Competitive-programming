#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	map<int , int> prev_index;	
	for(int i = 0; i < n; i++) cin >> a[i] , prev_index[a[i]] = -1;
	int prev = -1;
	prev_index[a[0]] = 0;
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(prev_index[a[i]] == -1) {
			if(prev == -1) {
				ans = i + 1;
			}
			else {
				ans = max(ans , i - prev);
			}
			prev_index[a[i]] = i;
		}
		else {
			prev = max(prev , prev_index[a[i]]);
			prev_index[a[i]] = i;
			ans = max(ans , i - prev);
		}
	} 
	cout << ans;
	return 0;
}