#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e6 + 1;
vector<int> cnt_divisors(maxn);

void seive()
{
	for(int i = 1; i < maxn; i++) {
			for(int j = i; j < maxn; j += i) cnt_divisors[j]++;
	}
}

int main()
{
	seive();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << cnt_divisors[n] << '\n';
	}
	return 0;
}
