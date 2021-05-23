#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
	int n;
	vector<int> Parent;
	vector<int> Size;
	DSU (int N): n (N), Parent (vector<int> (n)), Size (vector<int> (n, 1)) { iota (Parent.begin(), Parent.end(), 0); } // make_set()
	// void make_set() { for(int i = 0; i < n; i++) { Parent[i] = i, Size[i] = 1; } }
	int rep (int N) {
		if(Parent[N] == N) return N;
		return Parent[N] = rep(Parent[N]);
	}
	int Unite (int A, int B) {
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

	return 0;
}