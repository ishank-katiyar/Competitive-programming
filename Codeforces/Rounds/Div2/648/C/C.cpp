#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5 + 1;
vector<int> c1(maxn , 0);
vector<int> c2(maxn , 0);
vector<int> c3(maxn , 0);

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	int c = 1;
	for(int& i : a) scanf("%d" , &i) , c1[i] = c++;
	c = 1;
	vector<int> b(n);
	for(int& i : b) scanf("%d" , &i) , c2[i] = c++;
	for(int i = 1; i <= n; i++)  {
		int x = c1[i] - c2[i];
		if(x < 0) x += n;
		c3[x]++;
	}
	int ans = 0;
	for(int i = 0; i < maxn; i++) ans = max(ans , c3[i]);
	printf("%d" , ans);
	return 0;
}