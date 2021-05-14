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
	int n;
	cin >> n;
	string s;
	cin >> s;
	s.resize((int)(unique(s.begin() , s.end()) - s.begin()));
	cout << s << '\n';	
	return 0;
}

