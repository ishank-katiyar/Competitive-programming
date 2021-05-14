#include "bits/stdc++.h"
using namespace std;

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	stack<char> st;
	for(char& i : s) {
		if(st.empty() == true) st.push(i);
		else {
			if(i == st.top()) {
				st.pop();
				cnt++;
			}
			else st.push(i);
		}	
	}
	puts(cnt & 1 ? "Yes" : "No");
	return 0;
}
