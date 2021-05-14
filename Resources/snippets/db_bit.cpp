#include <bits/stdc++.h>

using namespace std;

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) { res += ", "; }
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}
	
template <size_t N> string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) { res += static_cast<char>('0' + v[i]); }
	return res;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}