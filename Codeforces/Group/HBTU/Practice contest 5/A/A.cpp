#include "bits/stdc++.h"
using namespace std;

int main()
{
	bool flag = false;
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(flag == false && a[i][0] == 'O' && a[i][1] == 'O') {
			a[i][0] = a[i][1] = '+';
			flag = true;
		} 
		if(flag == false && a[i][3] == 'O' && a[i][4] == 'O') {
			a[i][3] = a[i][4] = '+';
			flag = true;
		}
	}
	if(flag == false) {
		cout << "NO";
		return 0;
	}
	cout << (flag ? "YES" : "NO") << '\n';
	for(string& i : a) cout << i << '\n';
	return 0;
}
