#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	int n = (int) s.size();
	vector<int> a(n);
	int left = 0 , right = n - 1;
	int c = 1;
	for(char& i : s) {
		if(i == 'r') {
			a[left] = c;
			left++;
			c++;	
		}
		else {
			a[right] = c;
			right--;
			c++;
		}
	}
	for(int& i : a) cout << i << '\n';
	return 0;
}
