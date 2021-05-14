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
	sort(a.begin() , a.end());
	int sz = unique(a.begin() , a.end()) - a.begin();
	debug(sz);
	if(sz == n) cout << n;
	else if(sz == 1) cout << "1";
	else cout << n - 1;
	return 0;
}

