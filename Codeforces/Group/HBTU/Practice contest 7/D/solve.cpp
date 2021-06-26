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
	int n , m;
	cin >> n >> m;
	vector<int> a(n);
	for(int& i : a) cin >> i;
	vector<int> b(m);
	for(int& i : b) cin >> i;
	int ans = 0;
	int sum = 0;
	set<int> s;
	for(int i = 0; i < n; i++) sum += a[i] , s.insert(sum);
	sum = 0;
	for(int i = 0; i < m; i++) {
		sum += b[i];
		if(s.count(sum)) ans++;
	}
	cout << ans;
	return 0;
}

