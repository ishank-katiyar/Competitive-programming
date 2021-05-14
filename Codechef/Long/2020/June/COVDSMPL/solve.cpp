#include "bits/stdc++.h"
using namespace std;

int ask(int r , int c) {
	cout << "1 " << r << ' ' << c << ' ' << r << ' ' << c << '\n';
	cout.flush();
	int x;
	cin >> x;
	if(x == -1) {
		assert(false);
		exit(0);
	}
	return x;
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n , p;
		cin >> n >> p;
		vector<vector<int>> a(n , vector<int>(n , 0));
		for(int i = 1; i<= n; i++) {
			for(int j = 1; j <= n; j++) {
				int x = ask(i,j);
				a[i - 1][j - 1] = x;
			} 
		}
		cout << "2\n";
		for(auto& i : a) {
			for(int& j : i) cout << j << ' ';
			cout << '\n';
		}
		cout.flush();
		int x;
		cin >> x;
		assert(x == 1);
		if(x == -1) exit(0);
	}
	return 0;
}
