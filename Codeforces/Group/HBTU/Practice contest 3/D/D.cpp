#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d" , &x);
		sum += x;
		puts((sum- i - 1) & 1 ? "1" : "2");
	}
	return 0;
}