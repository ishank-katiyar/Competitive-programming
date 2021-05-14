#include "bits/stdc++.h"
using namespace std;

const int maxn = 501;
vector<int> win(maxn);

int main()
{
	int n;
	scanf("%d" , &n);
	__int64 k;
	scanf("%I64d" , &k);
	deque<int> d;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d" , &x);
		d.push_back(x);
	}
	int mx = *max_element(d.begin() , d.end());
	while(1) {
		int a = d.front();
		d.pop_front();
		int b = d.front();
		d.pop_front();
		if(a == mx || b == mx) {
			printf("%d" , mx);
			return 0;
		}
		else {
			if(a > b) win[a]++;
			else win[b]++;
			if(win[a] == k) {
				printf("%d" , a);
				return 0;
			}
			if(win[b] == k) {
				printf("%d" , b);
				return 0;
			}
		}
		if(a > b) d.push_front(a) , d.push_back(b);
		else d.push_front(b) , d.push_back(a);
	}
	assert(false);
	return 0;
}
