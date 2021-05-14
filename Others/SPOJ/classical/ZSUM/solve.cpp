#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...) //
#endif

const int mod = 10000007;

#define __int64 long long int

__int64 bpow(__int64 a , __int64 b) {
	__int64 ret = 1;
	while(b) {
		if(b & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	__int64 n , k;
	while(cin >> n >> k) {
		if(n == 0 && k == 0) break;
		__int64 ans = 0;
		ans += 2 * bpow(n - 1 , k);
		ans %= mod;
		ans += bpow(n , k);
		ans %= mod;
		ans += 2 * bpow(n - 1 , n - 1);
		ans %= mod;
		ans += bpow(n , n);
		cout << ans % mod << '\n';
	}	
	return 0;
}