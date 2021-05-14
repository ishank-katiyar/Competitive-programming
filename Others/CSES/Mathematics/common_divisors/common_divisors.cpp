#include "bits/stdc++.h"
using namespace std;

const int maxa = 1e6 + 1;
vector<int> c(maxa , 0);

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i] , c[a[i]]++;
	for(int i = maxa; i > 0; i--) {
		int cnt = 0; 
		for(int j = i; j < maxa; j += i) {
			cnt += c[j];
			if(cnt >= 2) {
				cout << i << '\n';
				return 0;
			}
		}
	}
	assert(false);	
	return 0;
}
