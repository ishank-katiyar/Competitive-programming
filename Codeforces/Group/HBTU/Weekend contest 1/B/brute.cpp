#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--)  {
		int a , b , c;
		scanf("%d %d %d" , &a , &b , &c);
		int aa = a;
		a += c;
		int cnt = 0;
		while(a > b && a >= aa) {
			cnt++;
			a-- , b++;
		}
		printf("%d\n" , cnt);
	}
	return 0;
}