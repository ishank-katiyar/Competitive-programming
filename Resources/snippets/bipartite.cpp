#include <bits/stdc++.h>

using namespace std;

class graph {
public:
	int n;
	vector<vector<int>> adj;
	vector<int> degree;
	vector<pair<int, int>> edge;
	vector<int> depth;
	vector<bool> covered;

	graph (int N) {
		n = N;
		adj.assign(n + 1, vector<int> ());
		degree.assign(n + 1, 0);
		depth.assign(n + 1, 0);
		covered.assign(n + 1, false);
	}

	void add (int X, int Y) {
		degree[X]++, degree[Y]++;
		edge.emplace_back(X, Y);
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}

	void do_dfs (int N) {
		covered.assign(n + 1, false);
		depth[N] = 0;
		dfs(N);
	}

	void dfs (int N) {
		if (covered[N] == true) return;
		covered[N] = true;
		for (int i: adj[N]) {
			if (covered[i] == false) {
				depth[i] = depth[N] + 1;
				dfs(i);
			} 
		}
	}
	vector<int> color;
	bool check_bipartite (int N_) {
		color.assign(n + 1, -1);
		bool ok = true;
		queue<int> q;
		color[N_] = 0;
		q.push(N_);
		while (q.empty() == false) {
			int N = q.front();
			q.pop();
			for (int i: adj[N]) {
				if(color[i] == -1) {
					color[i] = color[N] ^ 1;
					q.push(i);
				}
				else {
					ok &= (color[i] != color[N]); 
				}
			}
		}
		return ok;
	}
};



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}