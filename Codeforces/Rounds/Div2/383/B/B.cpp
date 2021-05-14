#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , x;
	scanf("%d %d",&n , &x);
	vector<int> ar(n);
	map<int , int> c;
	for(int& i : ar) scanf("%d", &i) , c[i]++;
	long long int cnt = 0;
	for(int i = 0; i < n; i++) cnt += c[ar[i] ^ x] - (x == 0);
	printf("%I64d" , cnt / 2);
	return 0;
}
