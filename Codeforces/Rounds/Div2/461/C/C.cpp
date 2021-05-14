#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int n , k;
	scanf("%I64d %I64d" , &n , &k);
	if(k == 1) {
		puts("Yes");
		return 0;
	}
	set<int> s;
	for(int i = 0; i < min(100LL , k); i++) s.insert(n % i);
	if((int) s.size() == min(100LL , k)) puts("Yes");
	else puts("No");
	return 0;
}