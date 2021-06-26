#include "bits/stdc++.h"
using namespace std;

bool open(char ch) {
	return ch == '(' || ch == '<' || ch == '{' || ch == '[';
}

bool close(char ch) {
	return ch == ')' || ch == '>' || ch == '}' || ch == ']';
}

bool diff(char ch , char ch1) {
	if(ch == '(') {
		return ch1 == ')';
	}
	if(ch == '<') return ch1 == '>';
	if(ch == '{') return ch1 == '}';
	return ch1 == ']';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	stack<char> st;
	int cnt = 0;
	for(char& i : s) {
		if(st.empty() == true) st.push(i);
		else {
			if(open(st.top()) && close(i)) {
				if(diff(st.top() , i) == false) cnt++;
				st.pop();
			}
			else st.push(i);
		}
	}
	if(st.empty() == true) printf("%d" , cnt);
	else puts("Impossible");
}
