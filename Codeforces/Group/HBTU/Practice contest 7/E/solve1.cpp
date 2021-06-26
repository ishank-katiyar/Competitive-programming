#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...) //
#endif

vector<pair<vector<int> , vector<int>>> com;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	for(int tt = 3; tt <= 1000; tt++) {
	int n;        
	n = tt;
	//cin >> n;
	if(n == 2) {
		//cout << "1\n1 1";
		return 0;
	}
	// BRUTE_FORCE
	/*
	__int64 mn = LLONG_MAX;
	for(int mask = 0; mask < (1 << n); mask++) {
		vector<int> f , se;
		__int64 sum1 = 0, sum2 = 0;
		for(int i = 0; i < n; i++) {
			if((mask >> i) & 1) {
				f.emplace_back(i + 1);
				sum1 += (i + 1);
			}
			else {
				se.emplace_back(i + 1);
				sum2 += (i + 1);
			}
		}
		if(abs(sum1 - sum2) < mn) {
			com.clear();
			mn = abs(sum1 - sum2);
			com.emplace_back(f , se);
		}
		if(abs(sum1 - sum2) == mn) {
			com.emplace_back(f , se);
		}
	}	
	debug(mn , com);
	*/
	__int64 sum = 0;
	sum = n;
	sum *= (n + 1);
	sum >>= 1;
	//if(sum % 2 == 0) cout << "0\n";
	//else cout << "1\n";
	__int64 sum1 = sum / 2;
	vector<int> ans;
	set<__int64> s;
	int c = 1;
	sum = 0;
	__int64 fd = -1;
	while(c <= n) {
		sum += c;
		s.insert(sum);
		c++;
		if(s.count(sum - sum1)) {
			fd = sum - sum1;
			break;
		}
		if(s.count(sum - sum1 - 1)) {
			fd = sum - sum1 - 1;
			break;
		}
	}
	if(fd == -1) {
		debug(n , fd);
	}
	assert(fd != -1);
	sum = 0;
	bool ok = false;
	__int64 sum2 = 0;
	for(int i = 1; i <= n; i++) {
		sum += i;
		if(fd == sum) {
			ok = true;
			continue;
		}
		if(ok) ans.emplace_back(i) , sum2 += i;
		if(sum1 == sum2) break; 
	}
	if(ans.empty() == true) {debug(n);}
	assert(ans.empty() == false);
	//cout << (int) ans.size() << ' ';
	//for(int& i : ans)  cout << i << ' ';
	}
	return 0;
}

