#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , l;
	scanf("%d %d" , &n , &l);
	set<int> s;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d" , &x);
		s.insert(x);
	}
	vector<int> a(s.begin() , s.end());
	int ans = 0.0;
	n = (int) a.size();
	for(int i = 1; i < n; i++) {
		ans = max(ans , a[i] - a[i - 1]);
	}
	long double w = (long double) ans / 2;
	int q1 = 0 , q2 = 0;
	if(s.count(0) == 0) {
		q1 = (int) *s.begin();	
	}
	if(s.count(l) == 0) {
		q2 = l - *(--s.end());
	}
	w = max({w , (long double)q1 , (long double)q2});
	cout << fixed << setprecision(10) << w;
	return 0;                    
}
