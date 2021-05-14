#include "bits/stdc++.h"
using namespace std;

const int maxn = 15e6 + 1;
vector<int> c(maxn , 0);

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	int gd = 0;
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]) , c[a[i]]++ , gd = __gcd(gd , a[i]);
	int mx = (int) *max_element(a.begin() , a.end());
	if(gd == mx) {
		puts("-1");
		return 0;
	}	
	vector<bool> used(maxn , true);
	int ans = 1e9;
	for(int i = gd + 1; i < maxn; i++) {
		if(used[i]){
		    int cnt = 0;
    		for(int j = i; j < maxn; j += i) {
    		    if(j != i) used[j] = false;
    		    cnt += c[j];
    		}
    		ans = min(ans , n - cnt);
		}
	}
	printf("%d" , ans);
	return 0;
}
