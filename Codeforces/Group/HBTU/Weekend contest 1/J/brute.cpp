#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	vector<long long int> pref(n);
	for(int i = 0; i < n; i++) {
		scanf("%d" , &a[i]);
		if(i == 0) pref[i] = a[i];
		else pref[i] += pref[i - 1] + a[i]; 
	} 
	vector<long long int> suf(n);
	suf[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		suf[i] += suf[i + 1] + a[i];
	}
	map<long long int , set<int>> m;
	for(int i = 0; i < n; i++) {
		m[suf[i]].insert(i);	
	}
	auto sum = [](int i , int j , vector<long long int> &pref) -> long long int{
		i++;
		j--;
		if(i > j) return LLONG_MAX;
		if(i == 0) return pref[j];
		return pref[j] - pref[i - 1];
	};
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(m.count(pref[i])) {
			auto it = m[pref[i]].upper_bound(i);
			while(it != m[pref[i]].end()) {
				int j = *it;
				if(sum(i , j , pref) == pref[i]) cnt++;
				it++;
			}
		}
	}
	printf("%d" , cnt);
	return 0;
}
