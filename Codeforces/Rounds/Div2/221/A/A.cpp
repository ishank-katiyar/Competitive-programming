#include "bits/stdc++.h"
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> a(10 , 0);
	for(char& i : s) a[i - '0']++;
	a[1]--;
	a[8]--;
	a[6]--;
	a[9]--;
	s = "";
	for(int i = 1; i <= 9; i++) while(a[i]--) s += (i + '0');
	s += "1869";
	while(a[0]--) s += (0 + '0');
	cout << s;
	return 0;
}