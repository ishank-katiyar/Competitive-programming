#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	int sum = 0;
	vector<int> sec;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++) scanf("%d %d" , &a[i].first , &a[i].second) , sum += a[i].first , sec.emplace_back(a[i].second);
	sort(sec.begin() , sec.end());
	for(int i = 0; i < n; i++) {
		if(a[i].second == sec[n - 1]) printf("%d " , (sum - a[i].first) * sec[n - 2]);
		else printf("%d " , (sum - a[i].first) * sec[n - 1]);
	}
	return 0;
}
