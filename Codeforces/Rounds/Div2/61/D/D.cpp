#include "bits/stdc++.h"
using namespace std;

bool check(vector<long long int> &a) {
	int n = (int) a.size();
	for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) if(__gcd(a[i] , a[j]) == 1) return false;
	long long int gd = 0;
	for(long long int& I : a) gd = __gcd(gd , I);
	return gd == 1;
}

long long int pow(int a , int b) {
	long long int ret = 1;
	while(b--) ret *= a;
	return ret;
}

int main()
{
	int n;
	scanf("%d" , &n);
	vector<long long int> a;
	if(n == 2) puts("-1");
	else {
		n -= 2;
		while(n--) a.emplace_back(6 * pow(2 , n));
		a.emplace_back(10);
		a.emplace_back(15);
		assert(check(a));
		for(long long int& i : a) printf("%I64d\n" , i);
	}
	return 0;
}

/*
2 * 3 = 6
2 * 5 = 10
3 * 5 = 15
*/
