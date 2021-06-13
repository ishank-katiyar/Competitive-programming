#include <bits/stdc++.h>

using namespace std;

template<class X, class Y, class Z = int64_t> X bpow (X a , Y b, int mod = -1) {
	X res = static_cast<X> (1);
	if (mod != -1 && (a < -mod || a >= mod)) a %= mod; 
	while(b) {
		if(b % 2 == 1) {
			if (mod != -1) {
        // (res *= a) %= mod;
        Z tmp = static_cast<Z> (1) * res * a;
        if (tmp < -mod || tmp >= mod) tmp %= mod;
        res = static_cast<X> (tmp);
      }
			else res *= a;
		}
		if (mod != -1) {
      // (a *= a) %= mod;
      Z tmp = static_cast<Z> (1) * a * a;
      if (tmp < -mod || tmp >= mod) tmp %= mod;
      a = static_cast<X> (tmp);
    }
		else a *= a;
		b /= 2;
	}
	return res;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	
	return 0;
}