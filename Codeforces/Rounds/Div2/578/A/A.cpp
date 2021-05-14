#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(args...)
#endif

int main()
{
	int n;
	scanf("%d" ,&n);
	string s;
	cin >> s;
	vector<bool> ar(10 , false);
	for(char& i : s) {
		if(i == 'L') {
			for(int j = 0; j < 10; j++) if(ar[j] == false) {
				ar[j] = true;
				break;
			}
		}
		else if(i == 'R') {
			for(int j = 9; j >= 0; j--) if(ar[j] == false) {
				ar[j] = true;
				break;
			}
		}
		else ar[i - '0'] = false;	
	}
	debug(ar);
	for(int i = 0; i < 10; i++) printf("%d" , (int)ar[i]);
	return 0;
}