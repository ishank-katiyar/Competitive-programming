#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n , m;
	cin >> n >> m;
	multiset<int> s;
	int x;
	for(int i = 0; i < n; i++) cin >> x , s.insert(x);
	for(int i = 0; i < m ;i++) {
		cin >> x;
		auto it = s.upper_bound(x);
		if(it == s.begin()) {
			cout << "-1\n";
			continue;
		}
		it--;
		cout << *it << '\n';
		s.erase(it);
	}
	cerr << "\n\nTime elapsed: "<<1000.00 * clock() / CLOCKS_PER_SEC <<" ms.\n";
	return 0;
}