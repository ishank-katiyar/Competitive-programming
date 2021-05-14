#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int>  ar(n+1);
	for(int i = 1; i <= n; i++) scanf("%d" , &ar[i]);
	bool flag = false;
	for(int i = 1; i <= n; i++) {
		if(i == ar[ar[ar[i]]]) flag = true;	
	}
	printf("%s" , (flag) ? "YES" : "NO");
	return 0;
}