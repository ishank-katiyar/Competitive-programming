#include "bits/stdc++.h"
#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug //
#endif
using namespace std;

int main()
{
	int n;         
	scanf("%d" , &n);
	vector<int> ar(n);
	for(int i = 0; i < n; i++) scanf("%d" , &ar[i]);
	if(count(ar.begin() , ar.end() , 1) > 0) {
		int moves =  n - count(ar.begin() , ar.end() , 1);
		printf("%d" , moves);
		return 0;
	}
	pair<int, int> pr = {0 , 10000000};
	for(int i = 0; i < n - 1; i++) {
		for(int j = i; j < n - 1; j++) {
			if(__gcd(__gcd(ar[i] , ar[i+1]) , __gcd(ar[j] , ar[j+1])) == 1) {
				if(pr.second - pr.first > j - i) pr.first = i , pr.second = j;
			}	
		}
	}
	debug(pr);
	if(pr == make_pair(0 , 10000000)) {
		puts("-1");
		return 0;
	}
	int moves = 0;
	for(int i = pr.first; i <= pr.second; i++) {
		ar[i + 1] = __gcd(ar[i] , ar[i+1]);
		moves++;
	}
	assert(ar[pr.second + 1] == 1);
	moves += n - count(ar.begin() , ar.end() , 1);
	printf("%d" , moves);
	return 0;
}