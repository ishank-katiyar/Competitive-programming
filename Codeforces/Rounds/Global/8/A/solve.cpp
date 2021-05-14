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
		__int64 a , b, n;
		cin >> a >> b >> n;
		__int64 a1 = a , b1 = b;
		int cnt = 0 , cnt2 = 0;
		bool ok = true;
		while(a <= n && b <= n) {
			if(ok) a += b;
			else b += a;
			ok = !ok;
			cnt++;
		}
		ok = false;
		while(a1 <= n && b1 <= n) {
			if(ok) a1 += b1;
			else b1 += a1;
			ok = !ok;
			cnt2++;
		}
		cout << min(cnt , cnt2) << '\n';
	}
	return 0;
}

