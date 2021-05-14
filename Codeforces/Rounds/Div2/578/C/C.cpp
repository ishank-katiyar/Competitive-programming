#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int n , m;
	scanf("%I64d %I64d" , &n , &m);
	int q;
	scanf("%d" , &q);
	long long int gd = __gcd(n , m);
	while(q--) {
		pair<int, long long int> a1 , a2;
		scanf("%d %I64d %d %I64d" , &a1.first , &a1.second , &a2.first , &a2.second);
		if(a2.first > a1.first) swap(a1,a2);
		long long int x1 , x2;
		if(a1.first == 1) {
			x1 = a1.second % (n / gd);
			if(x1 == 0) x1 = n / gd;
			x1 = a1.second - x1;
			x1 /= (n / gd);
		}
		else {
			x1 = a1.second % (m / gd);
			if(x1 == 0) x1 = m / gd;
			x1 = a1.second - x1;
			x1 /= (m / gd);
		}
		if(a2.first == 1) {
			x2 = a2.second % (n / gd);
			if(x2 == 0) x2 = n / gd;
			x2 = a2.second - x2;
			x2 /= (n / gd);
		}
		else {
			x2 = a2.second % (m / gd);
			if(x2 == 0) x2 = m / gd;
			x2 = a2.second - x2;
			x2 /= (m / gd);
		}
		puts(x1 == x2 ? "YES" : "NO");
	}
	return 0;
}