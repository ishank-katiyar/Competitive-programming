#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	multiset<int> s;
	int x;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		auto it = s.upper_bound(x);
		if(it == s.end()) {
			cnt++;
			s.insert(x);
		}
		else {
			s.erase(it);
			s.insert(x);
		}
	}
	cout << cnt;
	return 0;
}