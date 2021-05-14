#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , k;
	scanf("%d %d" , &n , &k);
	vector<int> a(n);
	for(int& i : a) scanf("%d" , &i);
	int pref = 0;
	vector<int> b(n);
	for(int i = 0; i < n; i++) scanf("%d" , &b[i]) , pref += (b[i] == 1 ? a[i] : 0);
	vector<int> sum(n);
	sum[0] = b[0] == 0 ? a[0] : 0;
	for(int i = 1; i < n; i++) {
		sum[i] += sum[i - 1] + (b[i] == 0 ? a[i] : 0);
	}
	for(int& i : sum) cerr << i << ' ';
	cerr << '\n';
	auto f = [](int L , int R , vector<int> &SUM) {
		if(L == 0) return SUM[R];
		return SUM[R] - SUM[L - 1];
	};
	int mx = 0;
	for(int i = k - 1; i < n; i++) {
		mx = max(mx , f(i - k + 1 , i , sum));
		cerr << f(i - k + 1 , i , sum) << '\n';
	}
	printf("%d" , pref + mx);
	return 0;
}