#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n , x;
	cin >> n >> x;
	vector<int> a(n);
	for(int &i : a) cin >> i;
	sort(a.begin() , a.end());
	int cnt = 0;
	int i = 0 , j = n-1;
	while(i < j) {
		if(a[i] + a[j] <= x) {
			cnt++;
			i++ , j--;
		}
		else {
			cnt++;
			j--;
		}
	} 
	if(i == j) cnt++;
	cout << cnt;
	return 0;
}