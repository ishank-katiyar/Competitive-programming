#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , t , c;
	scanf("%d %d %d" , &n , &t , &c);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]);
	int ways = 0;
	int index = 0;
	int cnt = 0;
	while(index < n) {
		if(a[index] > t) {
			ways += max(0 , cnt - c + 1);
			cnt = 0;
			index++;
		}
		else index++ , cnt++;
	}
	ways += max(0 , cnt - c + 1);
	printf("%d" , ways);
	return 0;
}
