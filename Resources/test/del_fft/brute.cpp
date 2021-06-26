#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	vector<int> aa (a.begin(), a.end()), bb (b.begin(), b.end());
	for_each (aa.begin(), aa.end(), [](int &x) -> int {x -= int('0'); return x;});
	for_each (bb.begin(), bb.end(), [](int &x) -> int {x -= int('0'); return x;});	
	int n = aa.size(), m = bb.size();
	vector<int> res (n + m - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res[i + j] += aa[i] * bb[j];
		}
	}
	int carry = 0;
	for (int i = n + m - 2; i >= 0; i--) {
		res[i] += carry;
		carry = res[i] / 10;
		res[i] %= 10;
	}
	res.front() += carry * 10;
	for(auto& i: res) cout << i;
	cout << '\n';
	return 0;
}
