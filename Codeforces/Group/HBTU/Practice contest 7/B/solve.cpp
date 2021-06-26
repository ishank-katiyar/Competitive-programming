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
	string s;
	cin >> s;
	int change = 0;
	bool ok = true;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			if(ok) s[i] = '0' , change++;
		}	
		else {
			if(ok) s[i] = '1' , change++ , ok = false;
		}
	}
	cout << change;
	return 0;
}

