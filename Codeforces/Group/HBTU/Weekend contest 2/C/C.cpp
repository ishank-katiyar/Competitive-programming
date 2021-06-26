#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin >> n;	
	int sum = 0;
	vector<pair<int, int>> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++)  {
		cin >> a[i].first >> a[i].second;
		sum += a[i].first;
		b[i] = a[i].second;
	}
	sort(b.begin() , b.end());
	int mx = b[n - 1];
	b.erase(--b.end());
	for(int i = 0; i < n; i++) {
		if(a[i].second == mx) {
			cout <<  (sum - a[i].first) * b[n - 2] << ' ';
		}
		else cout << (sum - a[i].first) * mx << ' ';
	}
	return 0;
}
