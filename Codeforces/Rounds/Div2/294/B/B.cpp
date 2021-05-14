#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	multiset<int> a;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d" , &x);
		a.insert(x);
	}
	multiset<int> b;
	for(int i = 0; i < n - 1; i++) {
		int x;
		scanf("%d" , &x);
		auto it = a.lower_bound(x);
		a.erase(it);
		b.insert(x);
	}
	assert((int) a.size() == 1);
	printf("%d\n"  , (int) *a.begin());
	for(int i = 0; i < n - 2; i++) {
		int x;
		scanf("%d" , &x);
		auto it = b.lower_bound(x);
		b.erase(it);
	}
	assert((int) b.size() == 1);
	printf("%d" , (int) *b.begin());
}
