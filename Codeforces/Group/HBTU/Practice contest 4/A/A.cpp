#include "bits/stdc++.h"
using namespace std;

int main()
{
	vector<int> a(4);
	for(int i = 0; i < 4; i++) cin >> a[i];
	string s;
	cin >> s;
	int sum = 0;
	for(char& i : s) sum += a[i - '1'];
	cout << sum;
	return 0;
}
