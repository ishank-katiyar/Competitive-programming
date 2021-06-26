#include "bits/stdc++.h"
using namespace std;

const int maxn = 3e4 + 1;
vector<int> c(maxn , 0);

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]) , c[a[i]]++;
	int cost = 0;
	for(int i = 1; i < maxn; i++) {
		while(c[i] > 1) {
			c[i]--;
			for(int j = i + 1; j < maxn; j++) {
				cost++;
				if(c[j] == 0) {
					c[j]++;
					break;
				}
			} 
		}
	}
	printf("%d" , cost);
	return 0;
}
