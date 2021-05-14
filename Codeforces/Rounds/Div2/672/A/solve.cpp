#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i: a) cin >> i;
		set<int> aa(a.begin(), a.end());
		vector<int> b(a);
		sort(b.rbegin(), b.rend());
		if (b == a && (int) aa.size() == n) cout << "NO" << '\n';
		else cout << "YES" << '\n';
		//auto check = [&] (vector<int> aa) -> bool {
			//vector<int> b(aa);
			//sort(b.rbegin(), b.rend());
			//if (b[0] == b[n - 1]) return false;
			//return aa == b;
			//int cnt = 0;
			//bool ok = false;
   //for (int i = 0; i < n; i++) {
    //if (aa[i] != b[i]) cnt++;
				//if (i > 0 && aa[i] != b[i] && aa[i - 1] != b[i]) ok = true;
   //}
			//if (cnt == 0) return true;
			//if (cnt == 2 && ok == true) return true;
			//return false;
		//};
		//cout << (check(a) == false ? "YES" : "NO") << '\n';
	}
	return 0;
}
