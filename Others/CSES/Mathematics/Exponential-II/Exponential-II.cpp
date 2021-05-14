#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

long long int bpow(long long int a , long long int b , const long long int md) {
	if(b == 0) return 1;
	long long int ret = 1;
	while(b) {
		if(b & 1) (ret *= a) %= md;
		(a *= a) %= md;
		b >>= 1;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	while(n--) {
		int a , b , c;
		cin >> a >> b >> c;
		if(a > 0 && b == 0 && c == 0) {
			cout << a << '\n';
			continue;
		}
		if(b == 0) {
			cout << "1\n";
			continue;
		}
		cout << bpow(a , mod - 1 + bpow(b , c , mod - 1) , mod) << '\n';
	}
	return 0;
}
