#include "bits/stdc++.h"
using namespace std;

int f(string s) {
	int ret = 0;
	for(char& i : s)  ret *= 10 , ret += (i - '0');
	return ret;
}

bool check(int h , int m) {
	string s = to_string(h);
	if((int) s.size() == 1) {
		s = "0" + s;
	}
	string ss = to_string(m);
	if((int) ss.size() == 1) ss = "0" + ss;
	s += ss;
	cerr << s << '\n';
	string s1(s);
	reverse(s1.begin() , s1.end());
	return s == s1;
}

int main()
{
	string s;
	cin >> s;
	int h = f(s.substr(0,2));
	int m = f(s.substr(3));
	m++;
	if(m == 60) {
		h++;
		h %= 24;
		m = 0;
	}
	while(1) {
		if(check(h,m)) {
			string s = to_string(h);
			if((int) s.size() == 1) {
				s = "0" + s;
			}	
			string ss = to_string(m);
			if((int) ss.size() == 1) ss = "0" + ss;
			s += ss;
	  	cout << s.substr(0 , 2) << ":" << s.substr(2);
	  	return 0;
		}
		m++;
		if(m == 60) {
			h++;
			h %= 24;
			m = 0;
		} 
	}
	assert(false);
	return 0;
}