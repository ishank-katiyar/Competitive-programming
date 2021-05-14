#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e6 + 1;
map<long long int , int> mp;

int main()
{
	for(int i = 1; i < maxn ; i++)	mp[(long long int)i * i * i] = i;
	int n;
	scanf("%d" , &n);
	while(n--) {
		int a,b;
		scanf("%d %d" , &a , &b);
		if(a > b) swap(a , b);
		puts(mp.count((long long int) a * b) && a % mp[(long long int) a * b] == 0 && b % mp[(long long int) a * b] == 0? "Yes" : "No");
	}
	return 0;
}