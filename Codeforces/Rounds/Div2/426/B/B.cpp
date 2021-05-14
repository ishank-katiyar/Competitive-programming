#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n , k;
	scanf("%d %d" , &n , &k);
	string s;
	cin >> s;
	vector<int> a(26);
	for(int i = 0; i < n; i++)  a[s[i] - 'A'] = i;
	int open = 0;
	bool ok = true;
	set<char> st;
	for(int i = 0; i < n; i++) {
		st.insert(s[i]);
		open = (int) st.size();
		ok &= open <= k;
		if(a[s[i] - 'A'] == i) {
			st.erase(s[i]);	
		}
	}
	puts(ok == false ? "YES" : "NO");
	return 0;
}
