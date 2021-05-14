#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...)
#endif

int main()
{
	int t;
	scanf("%d" , &t);
	while(t--) {
		int n , m;
		scanf("%d %d" , &n , &m);
		vector<string> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		string q = a[0];
		bool flag = false;
		for(int i = 0; i < m; i++) {
			for(char ch = 'a'; ch <= 'z'; ch++) {
				string q1 = q;
				q1[i] = ch;
				bool flag1 = true;
				for(int j = 0; j < n;j++) {
					int cnt = 0;
					for(int k = 0; k < m; k++) if(q1[k] != a[j][k]) cnt++;
					if(cnt > 1) {
						flag1 = false;
						break;
					}
				}
				if(flag1) {
					flag = true;
					printf("%s\n" , q1.c_str());
					break;
				}
			}
			if(flag) break;
		}
		if(flag == false) puts("-1");
	}
	return 0;
}