#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
	int n;
	vector<int> Parent;
	vector<int> Size;
	DSU (int N): n (N), Parent (vector<int> (n)), Size (vector<int> (n, 1)) { iota (Parent.begin(), Parent.end(), 0); }
	int rep (int N) { return Parent[N] == N ? N : Parent[N] = rep(Parent[N]); }
	bool Unite (int A, int B) { // return true if NOT UNITED, otherwise false
		int RA = rep(A), RB = rep(B);
		if(RA != RB) {
			if(Size[RA] < Size[RB]) { swap(RA, RB); }
			Parent[RB] = RA;
			Size[RA] += Size[RB];
			return true;
		}
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}