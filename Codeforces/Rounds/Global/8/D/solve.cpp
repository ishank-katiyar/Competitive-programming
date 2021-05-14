#ifdef UBUNTU
 #include "/mnt/c/users/ishan/coding_stuff/cp/testing/p.hpp"
 #include "/mnt/c/users/ishan/coding_stuff/cp/testing/debugger.hpp"
#else
	#include <bits/stdc++.h>
	#define debug(a...) //
	#define __int64_t __int64
#endif
using namespace std;

const int maxb = 20;
vector<int> cbit(maxb);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& i : a) cin >> i;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < maxb; j++) {
			if((a[i] >> j) & 1) cbit[j]++;
		}
	} 
	__int64_t ans = 0; 
	for(int i = 0; i < n; i++) {
		int x = 0;
		for(int j = 0; j < maxb; j++) {
			if(cbit[j]) {
				cbit[j]--;
				x |= (1 << j);
			}
		}
		ans += (__int64_t) x * x;
	}
	cout << ans;
	return 0;
}	
