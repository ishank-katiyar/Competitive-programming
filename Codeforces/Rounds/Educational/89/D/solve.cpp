#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...) //
#endif

const int maxa = 1e7 + 1;
vector<int> ar(maxa , -1);
vector<int> ar1(maxa , 0);
vector<bool> is_prime(maxa , true);

void seive() 
{
	for(int i = 2; i < maxa; i++) {
		if(is_prime[i]) {
			for(int j = i; j < maxa; j += i) {
				if(j != i) is_prime[j] = false;
				if(ar[j] == -1) ar[j] = i;
				ar1[j]++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	seive();
	int n;
	cin >> n;
	vector<pair<int , int>> an(n , make_pair(-1 , -1));
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(ar1[x] > 1) {
			int y = ar[x];
			while(x % y == 0) x /= y;
			an[i] = {y , x};
		}
	}	
	for(int i = 0; i < n; i++) cout << an[i].first << ' ';
	cout << '\n';
	for(int i = 0; i < n; i++) cout << an[i].second << ' ';
	return 0;
}