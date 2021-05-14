#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int , int>> a(n);
	for(int i = 0; i  <n; i++) cin >> a[i].second >> a[i].first;
	sort(a.begin() , a.end());
	int ans = 0;
	int x = 0;
	for(int i = 0; i < n; i++) {
		if(a[i].second >= x) x = a[i].first , ans++;
	} 
	cout << ans;
	return 0;
}