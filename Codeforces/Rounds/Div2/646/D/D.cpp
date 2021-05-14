#include "bits/stdc++.h"
using namespace std;

int ask(int n) {
	cout << "? " << n << ' ';
	for(int i = 1; i <= n - 1; i++) cout << i << ' ';
	cout << n << '\n';
	cout.flush();
	int x;
	cin >> x;
	if(x == -1) exit(0);
	return x;
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n , k;
		cin >> n >> k;
		vector<vector<int>> s;
		for(int i = 1; i <= k; i++) {
			int l;
			cin >> l;
			vector<int> ss;
			for(int j = 0; j < l; j++) {
				int x;
				cin >> x;
				ss.emplace_back(x);
			} 
			s.emplace_back(ss);
		}
		int mx = ask(n);
		int low = 1 , high = n;
		while(low < high) {
			int mid = low + high;
			mid >>= 1;
			if(ask(mid) == mx) high = mid;
			else low = mid + 1;
		}
		cerr << low << '\n';
		vector<int> ans;
		for(auto& i : s) {
			bool flag = false;
			for(int& j : i) if(j == low) flag = true;
			if(flag == false) {
				ans.emplace_back(mx);
			}
			else {
				int q1 = n - (int) i.size();
				cout << "? " << q1 << ' ';
				set<int> st;
				for(int k1 = 1; k1 <= n; k1++) st.insert(k1);
				for(int& j : i)  st.erase(j);
				int last = *(--st.end());
				st.erase(--st.end());
				for(int j : st) cout << j << ' ';
				cout << last << '\n';
				cout.flush();
				int x;
				cin >> x;
				ans.emplace_back(x);
			}
		}
		cout << "! ";
		for(int i = 1; i <= k; i++) cout << ans[i - 1] << ' ';
		string s1;
		cin >> s1;
		assert(s1 == "Correct");
	}
	return 0;
}

