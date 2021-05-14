#include "bits/stdc++.h"              	
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

int pow(long long int a , long long int b , int mod) {
	long long int ret = 1;
	while(b) {
		if(b & 1) (ret *= 1LL * a) %= mod;
		(a *= 1LL * a) %= mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	string s;
	cin >> s;
	int n = (int) s.size();
	int a , b;
	scanf("%d %d" , &a , &b);
	vector<int> pref(n);
	vector<int> suf(n);
	int mod = 0;
	for(int i = 0; i < n; i++) {
		mod *= 10;
		mod += (s[i] - '0');
		mod %= a;
		pref[i] = (mod + a) % a;
	}
	suf[n - 1] = (s[n-1] - '0') % b;
	for(int i = n - 2; i > 0; i--) {
		suf[i] = ((s[i] - '0') * pow(10 , n - i - 1, b) + suf[i + 1]) % b;				
	}
	debug(pref,suf);
	for(int i = 0; i < n - 1; i++) {
		if(pref[i] == 0 && suf[i + 1] == 0 && s[0] != '0' && s[i + 1] != '0') {
			puts("YES");
			cout << s.substr(0 , i + 1) << '\n' << s.substr(i + 1);
			return 0;
		}
	}
	puts("NO");
	return 0;
}
