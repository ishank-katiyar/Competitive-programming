#include <bits/stdc++.h>

using namespace std;

template<class X, class Y> X bpow(X a , Y b, int mod = -1) {
	X res(1);
	if (mod != -1) { a %= mod; }
	while(b) {
		if(b % 2 == 1) {
			if (mod != -1) (res *= a) %= mod;
			else res *= a;
		}
		if (mod != -1) (a *= a) %= mod;
		else a *= a;
		b /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}