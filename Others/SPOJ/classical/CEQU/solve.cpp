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
	for(int tt = 1; tt<= t; tt++) {
		int a , b , c;
		cin >> a >> b >> c;
		cout << "Case " << tt << ": " << ((c % __gcd(a , b)) ? "No" : "Yes")  << '\n';
	}	
	return 0;
}

