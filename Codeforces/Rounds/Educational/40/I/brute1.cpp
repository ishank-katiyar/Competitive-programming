#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
	int n;
	vector<int> Parent;
	vector<int> Size;
	DSU (int N): n (N), Parent (vector<int> (n)), Size (vector<int> (n, 1)) { iota (Parent.begin(), Parent.end(), 0); }
	// void make_set() { for(int i = 0; i < n; i++) { Parent[i] = i, Size[i] = 1; } }
	int rep(int N) {
		if(Parent[N] == N) return N;
		return Parent[N] = rep(Parent[N]);
	}
	int Unite(int A, int B) {
		int RA = rep(A), RB = rep(B);
		if(RA != RB) {
			if(Size[RA] < Size[RB]) { swap(RA, RB); }
			Parent[RB] = RA;
			Size[RA] += Size[RB];
			return 1;
		}
		return 0;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for (int i = 0; i < n - m + 1; i++) {
		DSU d (26);
		int ans = 0;
		for (int j = 0; j < m; j++) { ans += d.Unite (s[i + j] - 'a', t[j] - 'a'); }
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}
