#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

long long int pow(long long int a, long long int b) {
	if(b == 0) return 1;
	long long int ret = 1;
	while(b) {
		if(b & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		long long int a , b;
		cin >> a >> b;
		cout << pow(a , b) << '\n';
	}	
	return 0;
}
