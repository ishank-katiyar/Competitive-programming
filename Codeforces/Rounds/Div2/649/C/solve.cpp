#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...) //
#endif

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& i : a) cin >> i;
	debug(a);
	vector<int> ans(n , -1);
	bool ok = true;
	for(int i = 1; i <= n; i++) if(a[i - 1] > i) ok = false;
	if(ok == false) {
		cout << "-1";
		return 0;
	}	
	set<int> s;
	for(int i = 0; i <= n; i++) s.insert(i);
	for(int i = 1; i < n; i++) {
		if(a[i - 1] != a[i]) {
			ans[i] = a[i - 1];
			s.erase(a[i  - 1]);
		}
	}
	int x = a.back();
	s.erase(x);
	for(int i = 0; i < n; i++) {
		if(ans[i] == -1) {
			ans[i] = *s.begin();
			s.erase(s.begin());
		}
	}
	debug(s);
	for(int i = 0; i < n; i++) assert(ans[i] != -1);
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	return 0;
}
