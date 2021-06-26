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
	string b;
	cin >> b;
	int l = -1e9;
	int r = 1e9;
	for(int i = 4; i < n; i++) {
		if(b[i] == '1' && b[i - 1] == '0' && b[i - 2] == '0' && b[i - 3] == '0' && b[i - 4] == '0') {
			l = max(l , max({a[i] , a[i - 1] , a[i - 2] , a[i - 3] , a[i - 4]}) + 1);
		}
		if(b[i] == '0' && b[i - 1] == '1' && b[i - 2] == '1' && b[i - 3] == '1' && b[i - 4] == '1') {
			r = min(r , min({a[i] , a[i - 1] , a[i - 2] , a[i - 3] , a[i - 4]}) - 1);
		}
	}	
	assert(l <= r);
	cout << l << ' ' << r;
	return 0;
}

