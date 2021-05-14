#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	priority_queue<int , vector<int> , greater<int>> a;
	priority_queue<int> b;
	map<int, int> index;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push(x);
		index[x] = i;
	}
	string s;
	cin >> s;
	for(char& i : s) {
		if(i == '0') {
			int x = a.top();
			a.pop();
			cout << index[x] << ' ';
			b.push(x);	
		}
		else {
			int x = b.top();
			b.pop();
			cout << index[x] << ' ';
		}
	}
	return 0;
}
