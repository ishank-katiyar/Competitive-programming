#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif

const int maxa = 2e5 + 1;
vector<int> c(maxa , 0);

int main()
{
	int n , k;
	scanf("%d %d" , &n , &k);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d" , &x);
		c[x]++;
	} 
	vector<pair<int, int>> a;
	for(int i = 1; i < maxa; i++) {
		if(c[i] > 0) a.emplace_back(c[i] , i);
	}
	sort(a.rbegin() , a.rend());
	int max_copy = n / k;
	auto f = [](vector<pair<int , int>> &a , int I , int K) -> bool {
		int cnt = 0;
		for(auto& j : a) {
			int q = j.first / I;
			cnt += q;
			if(cnt >= K) break;
		}
		return cnt >= K;
	};
	int low = 1 , high = max_copy;
	while(low < high) {
		int mid = low + high;
		mid >>= 1;
		if(f(a , mid , k)) low = mid + 1;
		else  high = mid;
	}
	debug(low , high);
	if(f(a , low , k) == false) low--;
	vector<int> ans;
	for(auto& j : a) {
		int q = j.first / low;
		while((int) ans.size() != k && q--) ans.emplace_back(j.second);
	}
	assert((int) ans.size() == k);
	for(int& i : ans) printf("%d " , i);
	return 0;
}