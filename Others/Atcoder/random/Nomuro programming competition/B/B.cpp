#include "bits/stdc++.h"
using namespace std;

int main()
{
	string s;
	cin >> s;
	for(char& i : s) if(i == '?') i = 'D';
	cout << s;
	return 0;
}
