#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	set<long long int> q;
	for(int i = 1; i * i <= n; i++) {
		if(n % i) continue;
		q.insert((long long int) (n / i) * ( 1 + n - i + 1) / 2);
		q.insert((long long int) i * ( 1 + n - (n / i) + 1) / 2);
	}
	for(long long int i : q) printf("%I64d ", i);
	return 0;
}