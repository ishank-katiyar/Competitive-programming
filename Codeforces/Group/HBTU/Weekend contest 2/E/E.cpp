#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<string> a(n);
	for(string& i : a) cin >> i;
	map<string , bool> m;
	reverse(a.begin() , a.end());
	vector<string> ans;
	for(string& i  :a) {
		if(m.count(i) == 0) {
			ans.emplace_back(i);
			m[i] = true;
		}
	}
	for(string& i : ans) cout << i << '\n';
	return 0;
}
