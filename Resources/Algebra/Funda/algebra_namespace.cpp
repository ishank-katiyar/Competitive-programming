#include <bits/stdc++.h>

using namespace std;

namespace algebra {

template <class X, class Y> X bpow(X a, Y b, int mod = -1) { // a, b <= 1e18 && mod <= 1e9
	X res(1);
	if (mod != -1) {
		a %= mod;
	}
	while (b) {
		if (b % 2 == 1) {
			if (mod != -1) {
				(res *= a) %= mod;
			} else {
				res *= a;
			}
		}
		if (mod != -1) {
			(a *= a) %= mod;
		} else {
			a *= a;
		}
		b /= 2;
	}
	return res;
	/*
	* Original
	X res(1);
	while(b) {
	if(b % 2 == 1) res *= a;
	a *= a;
	b /= 2;
	}
	return res;
	*/
}

template <class X = int64_t> X gcd(X a, X b) { return b == 0 ? a : gcd (b, a % b); }

}; // namespace algebra

using namespace algebra;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
