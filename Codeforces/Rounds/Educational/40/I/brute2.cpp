#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for (int i = 0; i < n - m + 1; i++) {
		set<int> ss;
		for (int j = 0; j < m; j++) { 
			char c1 = s[i + j], c2 = t[j];
			if (c1 == c2) continue;
			ss.insert (c1);
			ss.insert (c2);
		}
		// cout << min ((int) ss.size (), 25)  << ' ';
		cout << ss.size () << ' ';
	}
	cout << '\n';
	return 0;
}
