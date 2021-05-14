#include  "bits/stdc++.h"
using namespace std;

int main()
{
	int s , k;
	scanf("%d %d" , &s , &k);
	vector<long long int> a;
	a.emplace_back(1);
	while((int) a.back() <= s) {
		long long int sum = 0;
		int n = (int) a.size();
		int i = n - 1;
		int ak = min(k , n);
		while(ak--) sum += a[i] , i--;
		a.emplace_back(sum); 
		cerr << sum << ' ';
	}
	cerr << '\n';
	vector<int> ans = {0};
	sort(a.rbegin() , a.rend());
	int n = (int) a.size();
	for(int i = 0; i < n && s > 0; i++) {
		if(a[i] <= s) {
			ans.emplace_back(a[i]);
			s -= a[i];
		}
	}
	assert(s == 0);
	printf("%d\n" , (int) ans.size());
	for(int& i : ans) printf("%d " , i);
	return 0;
}