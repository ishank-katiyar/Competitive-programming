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
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		vector<int> ans = {a[0]};
		for(int i = 1; i < n - 1; i++) {
			if((a[i] > a[i-1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) ans.emplace_back(a[i]);
		} 
		ans.emplace_back(a[n - 1]);
		cout << (int) ans.size() << '\n';
		for(int& i : ans) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}

