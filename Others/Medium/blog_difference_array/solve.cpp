#include <bits/stdc++.h>

using namespace std;


/**
	* @param a - initial array
	* @param query - query array - [li, ri, xi], li and ri are zero-based indexed
	* @return array after processing all queries
	*/
vector<int> HandleRangeUpdateQuery (vector<int> a, vector<vector<int>> query) {
	// creating another array to handle queries
	vector<int> b (a.size() + 1, 0);

	for (auto& q : query) {
		int l = q[0], r = q[1], x = q[2];
		// handling query
		b[l] += x;
		b[r + 1] -= x;
	}

	// calculating prefix sum of the array b
	for (int i = 1; i < b.size() - 1; i += 1) {
		b[i] += b[i - 1];
	}

	// adding all updates back to original array a
	for (int i = 0; i < a.size(); i += 1) {
		a[i] += b[i];
	}

	return a;
}


int main() {
	int n;
	cin >> n;
	vector<int> a (n);
	for (auto& i: a) cin >> i;
	vector<vector<int>> query;
	int q;
	cin >> q;
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		l--, r--;
		query.push_back ({l, r, x});
	}
	a = HandleRangeUpdateQuery (a, query);
	for (auto& i: a) cout << i << ' ';
	cout << '\n';
}