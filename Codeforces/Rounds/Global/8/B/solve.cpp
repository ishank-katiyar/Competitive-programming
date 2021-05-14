#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...) //
#endif

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	__int64 k;
	cin >> k;
	/*
	vector<__int64> p;
	for(int i = 2; i <= sqrt(k); i++) {
		if(k % i) continue;
		while(k % i == 0) p.emplace_back(i) , k /= i;
	}	
	if(k != 1) p.emplace_back(k);
	sort(p.begin() , p.end());
	debug(p);
	if((int) p.size() < 10) {
		while((int) p.size() != 10) p.emplace_back(1);
	}
	if((int) p.size() > 10) {
		multiset<__int64> d;
		for(auto& i : p) d.insert(i);
		while(1) {
			multiset<__int64> dd;
		 __int64 x = *d.begin();
		 d.erase(d.begin());
		 x *= *d.begin();
		 d.erase(d.begin());
		 dd.insert(x);
		 for(auto i : d) dd.insert(i);
		 d = dd;
		 debug(d);
		 if((int) d.size() == 10) {
		 	p.clear();
		 	for(int i : d) p.emplace_back(i);
		 	break;
		 }
		}
	}
	debug(p);
	assert((int) p.size() == 10);
	string s = "codeforces";
	string ans = "";
	for(int i = 0; i < 10; i++) {
		 while(p[i]--) { ans += s[i]; }
	}
	*/
	vector<int> a(10 , 1);
	while(1) {
		__int64 mul = 1;
		for(int& i : a) mul *= (__int64)i;
		if(mul >= k) break;
		auto it = min_element(a.begin() , a.end());
		int index = it - a.begin();
		a[index]++;
	}
	string ans = "";
	string s = "codeforces";
	for(int i = 0; i < 10; i++) while(a[i]--) ans += s[i];
	cout << ans << '\n';
	debug((int) ans.size());
	return 0;
}

