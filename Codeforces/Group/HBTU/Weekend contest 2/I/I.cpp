#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<pair<int , int> , vector<int>> m;
		int x = 0 , y = 0;
		m[make_pair(x , y)].emplace_back(0);
		int c = 1;
		for(char& i : s) {
			if(i == 'L') x--;
			if(i == 'R') x++;
			if(i == 'U') y++;
			if(i == 'D') y--;
			m[make_pair(x , y)].emplace_back(c++);
		}
		//debug(c , m);
		pair<int, int> ans = {0 , 1e9};
		for(auto& i : m) {
			if((int) i.second.size() > 1) {
				int sz = (int) i.second.size();
				vector<int> a(i.second);
				sort(a.begin() , a.end());
				for(int j = 1; j < sz; j++) {
					if(a[j] - a[j - 1] < ans.second - ans.first + 1) {
						ans = {a[j - 1] + 1 , a[j]};
					}
				}	
			}
		}
		if(ans == make_pair((int)0 , (int)1e9)) {
			cout << "-1\n";
			continue;
		}
		cout << ans.first << ' ' << ans.second << '\n';
	}
	return 0;
}