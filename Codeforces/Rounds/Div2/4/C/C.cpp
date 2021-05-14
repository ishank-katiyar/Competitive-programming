#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> m;
	while(n--) {
		string s;
		cin >> s;
		if(m.count(s)) {
			string s1 = to_string(m[s]);
			m[s]++;
			s += s1;
			cout << s << '\n';
		}	
		else {
			m[s]++;
			cout << "OK\n";
		}
	}
	return 0;
}
