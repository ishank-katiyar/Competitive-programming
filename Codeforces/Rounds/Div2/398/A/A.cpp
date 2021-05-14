#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> a(n);
	set<int> s;
	for(int i = 0; i < n; i++) scanf("%d" , &a[i]) , s.insert(a[i]);
	vector<vector<int>> ans(n);
	set<int> cur;
	for(int i = 0; i < n; i++) {
		cur.insert(a[i]);
		if(a[i] == *(--s.end())) {
		  while(cur.empty() == false && s.empty() == false && *(--cur.end()) == *(--s.end())) ans[i].emplace_back(*(--cur.end())) , cur.erase(--cur.end()) , s.erase(--s.end());
		}
	} 
	for(int i = 0; i < n; i++) {
		for(int& j : ans[i]) printf("%d " , j);
		puts("");
	}
	return 0;
}
