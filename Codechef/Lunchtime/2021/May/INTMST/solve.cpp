#warning partial soln (subtask 1 & subtask 2 only)

#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	int subtask;
	cin >> subtask;
	if (subtask == 1) {
		int t;
		cin >> t;
		while (t--) {
			int n, m;
			cin >> n >> m;
			assert (m == n - 1);
			if (n == 1) {
				cout << "!" << endl;
				int x;
				cin >> x;
				assert (x == 1);
				continue;
			} else if (n == 2) {
				cout << "! 0" << endl;
				int x;
				cin >> x;
				assert (x == 1);
				continue;
			}
			cout << "! -1" << endl;
			int x;
			cin >> x;
			assert (x == 1);
		}
	} else if (subtask == 2) {
		int t;
		cin >> t;
		while (t--) {
			int n, m;
			cin >> n >> m;
			assert (n == m);
			vector<int> wei (m);
			iota (wei.begin(), wei.end(), 1);
			vector<int> pp (m);
			int cur_idx = m - 1;
			for (int i = 0; i < m; i++) {
				cout << "? ";
				for (int j = 0; j < m; j++) {
					cout << wei[j];
					if (j < m - 1) cout << " ";
				}
				cout << endl;
				vector<int> ret (n - 1);
				cin >> ret[0];
				assert (ret[0] != -1);
				for (int j = 1; j < n - 1; j++) cin >> ret[j];
				int ret_idx = -1;
				for (int j = 0; j < m; j++) {
					if (count (ret.begin(), ret.end(), j) == 0) {
						ret_idx = j;
						break;
					}
				}				
				assert (ret_idx != -1);
				pp[cur_idx] = ret_idx;
				wei.push_back (wei.front());
				wei.erase (wei.begin());
				cur_idx--;
			}
			cout << "!";
			for (int i = 0; i < m; i++) {					
				cout << " " << pp[i];
			}
			cout << endl;
			int x;
			cin >> x;
			assert (x == 1);
		}
	} else {
		assert (false);
	}
	return 0;
}
