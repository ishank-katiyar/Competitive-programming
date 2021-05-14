#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++) scanf("%d %d" , &a[i].first , &a[i].second);
	vector<int> prime;
	for(int i = 2; i <= (int) sqrt(a[0].first); i++) {
		if(a[0].first % i == 0) {
			prime.emplace_back(i);
			while(a[0].first % i == 0) a[0].first /= i;
		}
	}
	if(a[0].first != 1) prime.emplace_back(a[0].first);
	for(int i = 2; i <= (int) sqrt(a[0].second); i++) {
		if(a[0].second % i == 0) {
			prime.emplace_back(i);
			while(a[0].second % i == 0) a[0].second /= i;
		}
	}
	if(a[0].second != 1) prime.emplace_back(a[0].second);
	for(int& i : prime) {
		bool flag = true;
		for(int j = 1; j < n; j++) {
			if(a[j].first % i && a[j].second % i) {
				flag = false;
				break;
			}
		}
		if(flag) {
			printf("%d" , i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}