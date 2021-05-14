#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , m;
	scanf("%d %d" , &n , &m);
	int ans = 1;
	while(!((ans / 2) >= n && (ans / 3) >= m && ((ans / 2) + (ans / 3) - (ans / 6)) >= n + m)) ans++; 
	printf("%d" , ans);
	return 0;
}