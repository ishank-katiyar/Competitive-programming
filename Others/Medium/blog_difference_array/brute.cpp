#include <bits/stdc++.h>

using namespace std;

/**
	* @param a - initial array
	* @param query - query array - [li, ri, xi], li and ri are zero-based indexed
	* @return array after processing all queries
 */
vector<int> HandleRangeUpdateQuery (vector<int> a, vector<vector<int>> query) {
	// brute force method
	for (auto& q: query) {
		int l = q[0], r = q[1], x = q[2];
		for (int i = l; i <= r; i += 1) {
			a[i] += x;
		}
	}
	return a;
}

int main() {

	return 0;
}
