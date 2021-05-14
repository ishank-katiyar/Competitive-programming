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
	int t;
	cin >> t;
	while(t--) {
		int n , x;
		cin >> n >> x;
		vector<int> a(n);
		int sum = 0 , sum1 = 0;
		for(int& i : a) cin >> i , sum += i;
		sum1 = sum;
		vector<int> b(a);
		reverse(b.begin() , b.end());
		while(a.empty() == false) {
			if(sum % x) break;
			sum -= (int)a.back();
			a.pop_back();
		}
		while(b.empty() == false) {
			if(sum1 % x) break;
			sum1 -= (int) b.back();
			b.pop_back();
		}
		x = max((int) a.size() , (int) b.size());
		if(x == 0) {
			cout << "-1\n";
			continue;
		}
		cout << x << '\n';
	}	
	return 0;
}

