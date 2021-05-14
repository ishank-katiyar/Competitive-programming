#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d" , &n);
		set<int> a = {0};
		for(int i = 1; i <= sqrt(n); i++)  a.insert(i) , a.insert(n / i);
		printf("%d\n" , (int)a.size());
		for(int i : a) printf("%d ", i);
		puts("");  
	}
	return 0;
}