#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...) 
#endif

const int maxn = 1e5 + 1;
vector<int> b(maxn , 0);
vector<int> s(maxn , 0);

int main()
{
	int n , s2;
	scanf("%d %d" , &n , &s2);
	for(int i = 0 ; i < n; i++) {
		char ch;
		cin >> ch;
		int p , q;
		scanf("%d %d" , &p , &q);
		debug(ch , p , q);
		(ch =='B' ? b[p] : s[p]) += q;
	}
	int s1 = s2;
	vector<pair<int , int>> a;
	for(int i = maxn - 1; i >= 0; i--) {
		if(s[i] > 0) {
			a.emplace_back(i , s[i]);
		}
	}
	sort(a.begin() , a.end());
	int sz = (int) a.size();
	for(int i = min(sz , s2) - 1; i >= 0; i--) {
		printf("S %d %d\n" , a[i].first , a[i].second);
	}
	s1 = s2;
	for(int i = maxn - 1; i >= 0; i--) {
		if(b[i] > 0 && s1 > 0) {
			s1--;
			printf("B %d %d\n" , i , b[i]);
		}
	}
	return 0;
}
