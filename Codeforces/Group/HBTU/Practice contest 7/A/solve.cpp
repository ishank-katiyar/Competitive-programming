#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include "personal/debugger.hpp"
#else
	#define debug(a...) //
#endif

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n , m;
	cin >> n >> m;
	vector<string> a(n);
	for(string& i : a) cin >> i;
	set<int> st;
	for(int i = 0; i < m; i++) {
		string s = "";
		for(int j = 0; j < n; j++) s += a[j][i];
		char ch = *max_element(s.begin() , s.end()); 
		for(int k = 1; k <= n; k++) {
			if(s[k - 1] == ch) st.insert(k);
		}
	}	
	cout << (int) st.size();
	return 0;
}

