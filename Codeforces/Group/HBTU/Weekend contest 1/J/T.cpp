#include "bits/stdc++.h"
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}
/*
int main(int argc, char* argv[]) {
	int t = 1;
	t = atoi(argv[1]);
	int n = atoi(argv[2]);
	int m = atoi(argv[3]);
	printf("%d\n",t);
	map<pair<int, int>, int> mp;
	while(t--) {
		mp.clear();
		printf("%d %d\n",n, m);
		for(int i = 1; i <= m; i++) {
			int x = rand(1, n);
			int y = rand(1, n);
			if(x == y || mp[{x, y}] || mp[{y, x}]) {
				i--;
				continue;
			}  
			mp[{x, y}]++;
			printf("%d %d\n",x, y);
		}
	}
	return 0;
}
*/

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	cout << n << '\n';
	for(int i = 1; i <= n; i++) {
		cout << rand(1 , 10000000) * (rand(1,100) & 1 ? -1 : 1) << ' ';
		//cout << "1 -1 ";
	}
	return 0;
}