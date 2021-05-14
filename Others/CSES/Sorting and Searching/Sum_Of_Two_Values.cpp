#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n , x;
	cin >> n >> x;
	vector<pair<int, int>> a(n);
	int c = 1;
	for(auto& i: a) cin >> i.first , i.second = c++;
	sort(a.begin() , a.end());
	int i = 0 , j =  n-1;
	while(i < j) {
		if(a[i].first + a[j].first == x) {
			cout << a[i].second << ' ' << a[j].second;
			return 0;
		}
		if(a[i].first + a[j].first < x) i++;
		else j--;
	}
	cout << "IMPOSSIBLE";
	return 0;
}