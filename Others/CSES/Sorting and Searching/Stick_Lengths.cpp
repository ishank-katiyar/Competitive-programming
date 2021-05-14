#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin() , a.end());
	long long int above = 0;
	for(int i = 1; i < n; i++) above += a[i] - a[0];
	long long int ans = above;
	long long int below = 0;
	for(int i = 1; i < n; i++) {
		below += i * (a[i] - a[i-1]);
		above -= (n - i) * (a[i] - a[i-1]);
		ans = min(ans , above + below);	
	}
	cout << ans;
	return 0;
}

/*
1 2 2 3 5
8
5
5
6
12
*/