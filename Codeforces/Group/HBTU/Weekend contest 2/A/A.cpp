#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 	
	#define debug(a...)
#endif

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<bool> a(10 , false);
	for(char& j : s) {
		if(isdigit(j)) {
			int room  = j - '0';
			a[room] = false;	
		}
		else {
			if(j == 'L') {
				for(int i = 0; i < 10; i++) {
					if(a[i] == false) {
						a[i] = true;
						break;
					}
				}
			}
			else {
				for(int i = 9; i >= 0; i--) {
					if(a[i] == false) {
						a[i] = true;
						break;
					}
				}	
			}
		}
		debug(a);
	}
	string q = "";
	for(bool i : a) q += (char)('0' + (int)(i));
	cout << q;
	return 0;
}