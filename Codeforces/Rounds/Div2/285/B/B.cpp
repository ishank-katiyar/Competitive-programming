#include "bits/stdc++.h"
using namespace std;

map<string , string> m;

int main()
{
	int n;
	cin >> n;
	vector<pair<string , string>> a(n);
	for(auto& i : a) {
		cin >> i.first >> i.second;
		m[i.first] = i.second;
	}
	vector<pair<string , string>> ans;
	for(int i = 0; i < n; i++) {
		string s = a[i].first;
		string s1 = s;
		while(m.count(s)) {
			s = m[s];
		}	
		if(s1 != s) ans.emplace_back(s1 , s);
		while(m.count(s1)) {
			s = s1;
			s1 = m[s1];
			m.erase(s);	
		}
	}
	cout << (int) ans.size() << '\n';
	for(auto& i : ans) cout << i.first << ' ' << i.second << '\n';
	return 0;
}

