/*

n + x * m == k + y * a
mx - ay = k - n


n = 8
m = 7
a = 7
k = 9


*/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...) //
#endif

#warning UNSOLVED

template<class T> T gcd(T a , T b , T& x , T& y) {
	if(b == 0) { x = 1 , y = 0; return a; }
	T x1 , y1;
	T gd = gcd(b , a % b , x1 , y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return gd; 
}

const __int64 q = 1e18;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	__int64 n , m , a , k;
	while(cin >> n >> m >> a >> k) {
		if(n + m + a + k == 0) break;
		__int64 x , y;
		__int64 gd = gcd(m , a , x , y);
		if((n == 0 && m == 0) || (a == 0 && k == 0)) {
			cout << "Impossible\n";
			continue;
		}        
		if(m == 0 && a == 0) {
			if(n == k) cout << n << '\n';
			else cout << "Impossible\n";
			continue;
		}
		if(m == 0) {
			if(n >= k && (n - k) % a == 0) cout << n << '\n';
			else cout << "Impossible\n";
			continue;
		}
		if(a == 0) {
			if(k >= n && (k - n) % m == 0) cout << k << '\n';
			continue;
		}
		if(((__int64) abs(k - n)) % gd) {
			cout << "Impossible\n";
			continue;
		}
		assert(gd > 0);
		__int64 mul = (k - n) / gd;
		x *= mul;
		y *= mul;
		y *= -1;
		__int64 ans = n + x * m;
		while(ans >= 0) {
			x -= (a / gd);
			y -= (m / gd);
			ans = n + x * m;
		}
		while(ans <= 0 || ans < n || ans < k) {
			x += (a / gd);
			y += (m / gd);
			ans = n + x * m;
		}
		__int64 x1 = n;
		bool ok = false;
		if(x1 == 0) x1 += m;
		while(x1 < q) {
			if(x1 >= k && (x1 - k) % a == 0) {
				ok = true;
				if(ans != x1) { debug(n , m , a , k , ans , x1); }
				assert(ans == x1);
				break;
			}
			x1 += m;
		}
		assert(ok);
		cout << ans << '\n';
	}
	return 0;
}
