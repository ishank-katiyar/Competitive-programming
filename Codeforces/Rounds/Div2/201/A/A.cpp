#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	int gd = 0;
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]) , gd = __gcd(gd , a[i]);
	puts(((*max_element(a.begin() , a.end()) / gd) - n) & 1 ? "Alice" : "Bob");
	return 0; 
}