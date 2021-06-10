#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
using namespace __gnu_pbds;

template<class X, class cmp = less<X>>
using ordered_set = tree<X, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ordered_set<int> s;
		for (int i = 0; i < n; i++) s.insert (i);
		vector<int> a (n);
		int idx = 0;
		int move = 1;
		while (s.empty() == false) {
			idx += move++;
			idx %= int(s.size());
			a[*s.find_by_order(idx)] = move - 1;
			s.erase (*s.find_by_order(idx));
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}
