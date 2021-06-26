#include "bits/stdc++.h"
using namespace std;

bool CBS(string s) {
	stack<char> st;	
	for(char& i : s) {
		if(st.empty() == true) st.push(i);
		else {
			if(st.top() == '(' && i == ')') st.pop();
			else st.push(i);
		}
	}
	return st.empty() == true;
}

int main()
{
	int n;
	cin >> n;
	if(n & 1) {
		puts("No");
		return 0;
	}
	string s;
	cin >> s;
	string q;
	int index = -1;
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == '(') {
			index = i;
			break;
		}	
	}	
	q += '(';
	for(int i = 0; i < n; i++) {
		if(i == index) continue;
		q += s[i];
	}
	if(CBS(q)) puts("Yes");
	else puts("No");
}