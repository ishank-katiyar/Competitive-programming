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
		int n , m , x;
		cin >> n >> x >> m;
		int low = -1 , high = -1;
		bool ok = false;
		for(int i = 0; i < m; i++) {
			int x1 , y1;
			cin >> x1 >> y1;
			if(x1 <= x && y1 >= x && ok == false) {
				ok = true;
				if(low == -1) low = x1;
				else low = min(low , x1);
				if(high == -1) high = y1;
				else high = max(high , y1);
			}
			if((y1 >= low && high >= x1) && ok == true) {
				low = min(low , x1);
				high = max(high , y1);
			}
		}
		if(low == -1 && high == -1) cout << "1\n";
		else cout << high - low + 1 << '\n';
	}	
	return 0;
}

