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
	for(int a = 0; a <= 10; a++) {
		for(int b = 0; b <= 10; b++) {
			for(int c = 0; c <= 10; c++) {
				for(int d = 0; d <= 10; d++) {
					if(a + b + c + d == 0) continue;
					cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
				}
			}
		}
	}	
	cout << "0 0 0 0";
	return 0;
}
