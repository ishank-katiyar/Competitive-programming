#include "bits/stdc++.h"
using namespace std;

bool f(vector<int> &a) {
	for(int& i : a) if(i == 1) return false;
	return true;
}

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--)  {
		int n , m;
		scanf("%d %d" , &n , &m);
		vector<vector<int>> ar(n , vector<int>(m , 0));
		for(auto& i : ar) for(int& j : i) scanf("%d" , &j);
		int total1 = 0 , total2 = 0;
		for(auto& i : ar) {
			total1 += f(i);
		}
		for(int i = 0; i < m; i++) {
			vector<int> a;
			for(int j = 0; j < n; j++) a.emplace_back(ar[j][i]);
			total2 += f(a);
		}
		int x = (min(total1 , total2) & 1) ^ 1;
		puts(x ? "Vivek" : "Ashish");
	}
	return 0;
}
