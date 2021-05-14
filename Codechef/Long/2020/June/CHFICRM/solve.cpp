#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n;
		scanf("%d" , &n);
		multiset<int> s;
		bool ok = true;
		vector<int> a(n);
		for(int& i : a) scanf("%d" , &i);
		for(int& i : a) {
			if(i != 5) {
				int x = i - 5;
				if(x == 5) {
					if(s.count(x)) {
						s.erase(s.find(x));
						s.insert(i);
					}
					else {
						ok = false;
						break;
					}
				}
				else if(x == 10) {
					if(s.count(x)) {
						s.erase(s.find(x));
						s.insert(i);
					}
					else if(s.count(5) >= 2) {
						s.erase(s.find(5));
						s.erase(s.find(5));
						s.insert(i);
					}
					else {
						ok = false;
						break;
					}
				}
			}
			else s.insert(5);
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
