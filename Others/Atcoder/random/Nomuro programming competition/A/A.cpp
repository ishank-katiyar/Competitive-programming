#include "bits/stdc++.h"
using namespace std;

int main()
{
	int h1 , m1 , h2 , m2 , k;
	scanf("%d %d %d %d %d" , &h1 , &m1 , &h2 , &m2 , &k);
	int len = 0;
	len += (60 - m1);
	len += (h2 - h1 - 1) * 60;
	len += m2;
	if(h1 > h2 || (h1 == h2 && m1 > m2)) len = 24 * 60 - len;
	printf("%d" , max(len - k , 0));
	return 0;
}