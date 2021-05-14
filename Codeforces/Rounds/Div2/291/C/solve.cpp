#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
	#include "personal/debugger.hpp"
#else 
	#define debug(a...)
#endif


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const __int64 mod = 1e12 + 39;
const int p = (int) uniform_int_distribution<int> (4 , 100) (rng);
const int maxn = 6e5 + 1;
vector<__int64> pp(maxn);
set<__int64> Hash;
vector<int> c = {'a' , 'b' , 'c'};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	pp[0] = 1;
	for(int i = 1; i < maxn; i++) pp[i] = pp[i - 1] * p % mod;
	int n , m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int sz = (int) s.size();
		__int64 h = 0;
		for(int j = 0; j < sz; j++) h += (s[j] - 'a' + 1) * pp[j] % mod , (h += mod) %= mod;
		Hash.insert(h);
	} 
	debug(Hash);
	for(int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		int sz = (int) s.size();
		__int64 h = 0;
		for(int j = 0; j < sz; j++) h += (s[j] - 'a' + 1) * pp[j] % mod , (h += mod) %= mod;
		bool ok = false;
		for(int j = 0; j < sz; j++) {
			for(int& k : c) {
				if(k == s[j]) continue;
				__int64 h1 = (k - s[j]) * pp[j] % mod;
				h1 += mod;
				__int64 x = h + h1;
				x %= mod;
				debug(x);
				ok |= (Hash.count(x) > 0);
			}
		}
		cout << (ok ? "YES" : "NO") << '\n'; 
	}
	cerr << "\nTime elapsed: "<< 1000.00 * clock() / CLOCKS_PER_SEC <<" ms.\n";
	return 0;
}
