#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x , n;
	cin >> x >> n;
	multiset<int> dis;
	dis.insert(x);
	set<int> s;
	s.insert(0);
	s.insert(x);
	int y;
	for(int i = 0; i < n; i++) {
		cin >> y;
		if(y == x) {
			cout << *(--dis.end()) << ' ';
			continue;	
		}
		if(y == 0) {
			cout << *(--dis.end()) << ' ';
			continue;
		}
		auto it = s.upper_bound(y);
		int z = *it;
		int z1 = *(--it);
		auto it1 = dis.lower_bound(z - z1);
		s.insert(y);
		dis.erase(it1);
		dis.insert(z - y);
		dis.insert(y - z1);
		cout << *(--dis.end()) << ' ';
	} 
	return 0;
}