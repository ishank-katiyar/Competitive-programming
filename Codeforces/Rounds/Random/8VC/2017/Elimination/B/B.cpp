#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , m;
	scanf("%d %d" , &n , &m);
	set<string> s , a , b;
	int an = n , am = m;
	while(n--) {
		string s1;
		cin >> s1;
		a.insert(s1);
		s.insert(s1);
	}
	while(m--) {
		string s1;
		cin >> s1;
		b.insert(s1);
		s.insert(s1);
	}
	int k = (int) s.size();
	int rest = an + am - k;
	am -= rest % 2;
	puts(an > am ? "YES" : "NO");
	return 0;
}
