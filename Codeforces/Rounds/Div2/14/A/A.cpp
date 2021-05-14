#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , d;
	cin >> n >> d;
	string s;
	cin >> s;
	bool flag = true;
	int cnt = 0;
	for(int i = 0; i < n - 1; i++) {
		int j;
		for(j = min(i + d , n - 1); j > i; j--) {
			if(s[j] == '1') {
				i = j - 1;
				cnt++;
				break;
			}	
		}
		if(j == i) {
			puts("-1");
			return 0;
		}
	}	
	cout << cnt;
	return 0;
}
