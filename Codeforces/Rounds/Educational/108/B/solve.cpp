#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
	return '"' + s + '"';
}

string to_string(const char* ch) {
	return to_string((string)ch);
}

string to_string(char ch) {
	return (string)"'" + ch + (string)"'";
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

template<class A, class B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class A>
string to_string(A a) {
	string res = "{";
	bool first = true;
	for(const auto& x: a) {
		if(first == false) res += ", ";
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

void debug() {cerr << "]\n";}

template<class H, class... T>
void debug(H head, T... tail) {
	cerr << to_string(head) << " ";
	debug(tail...);
}

#ifdef LOCAL
	#define debug(...) cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else 
	#define debug(...) 
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> a (n, vector<int> (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) continue;
				int cost = INT_MAX;
				if (i - 1 >= 0) cost = min (cost, j + 1 + a[i - 1][j]);
				if (j - 1 >= 0) cost = min (cost, i + 1 + a[i][j - 1]);
				a[i][j] = cost;
			}
		}
		debug (a);
		cout << (k >= a[n - 1][m - 1] && k <= m * n - 1 ? "YES" : "NO") << '\n';
	}
	return 0;
}
