#include <bits/stdc++.h>

using namespace std;

string to_string(string s) 				{ return '"' + s + '"'; }

string to_string(const char* ch) 	{ return string(ch); }

string to_string(char ch) 				{ return (string)"'" + ch + (string)"'"; }

string to_string(bool b) 					{ return (b ? "true" : "false"); }

template<class A, class B>
string to_string(pair<A, B> p) 		{ return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}
	
template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
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
void debug(H head, T... tail) 		{ cerr << to_string(head) << " "; debug(tail...); }

#ifdef LOCAL
	#define debug(...) cerr << "[" << #__VA_ARGS__ << " ] = ["; debug(__VA_ARGS__);
#else 
	#define debug(...) 
#endif

class graph {
public:
	int n;
	vector<vector<pair<int, int>>> adj;
	vector<int> degree;
	vector<pair<int, int>> edge;
	vector<int> depth;
	vector<bool> covered;
	vector<int> subtree;
	vector<bool> is;

	graph (int N) {
		n = N;
		adj.assign(n + 1, vector<pair<int, int>> ());
		degree.assign(n + 1, 0);
		depth.assign(n + 1, 0);
		covered.assign(n + 1, false);
		subtree.assign(n + 1, 0);
		is.assign(n + 1, false);
	}

	void add (int X, int Y, int W) {
		degree[X]++, degree[Y]++;
		edge.emplace_back(X, Y);
		adj[X].push_back(make_pair(Y, W));
		adj[Y].push_back(make_pair(X, W));
	}

	void assign (const vector<int> k) {
		for (auto& i: k) { is[i] = true; }
	}

	int dfs (const int N) {
		if (covered[N]) return 0;
		covered[N] = true;
		int ret = is[N];
		for (auto& [v, w]: adj[N]) {
			if (covered[v] == false) {
				depth[v] = depth[N] + 1;
				ret += dfs (v);
			}
		}
		subtree[N] = ret;
		return ret;
	}

	int bfs () {
		// covered.assign(n + 1, false);
		// for (auto& i: k) {
		// 	covered[i] = true;
		// }
		// covered = is;
		// int ans = 0;
		// for (auto& u: k) {
		// 	vector<int> dist;
		// 	for (auto& [v, w]: adj[u]) {
		// 		if (covered[v] == false) {
		// 			covered[v] = true;
		// 			int cnt = 0;
		// 			if (depth[v] > depth[u]) {
		// 				cnt = subtree[v];
		// 			}	else if (depth[u] > depth[v]) {
		// 				cnt = (int) k.size() - subtree[u];
		// 			}	else {
		// 				debug (u, v);
		// 				assert (false);
		// 			}
		// 			if (cnt > 0 ) dist.push_back (w);
		// 		}
		// 	}	
		// 	debug (u, dist);
		// 	if (dist.empty()) {
		// 		continue;
		// 	}
		// 	ans += (count (dist.begin(), dist.end(), *min_element(dist.begin(), dist.end())) == 1);		
		// }
		// debug (ans);
		// return ans + k.size();
		int sz = count (is.begin(), is.end(), true);
		int ans = 0;
		for (int u = 1; u <= n; u++) {
			if (is[u]) continue;
			int cnt = 0;
			for (auto& [v, w]: adj[u]) {
				if (depth[v] > depth[u]) {
					cnt += (subtree[v] > 0);
				}	else if (depth[u] > depth[v]) {
					cnt += (sz - subtree[u]) > 0;
				}	else {
					debug (u, v);
					assert (false);
				}
			}
			ans += cnt > 1;	
		}
		return ans + sz;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	graph G (n);
	for (int i = 1; i < n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		G.add (x, y, w);
	}
	vector<int> K (k);
	for (int i = 0; i < k; i++) {
		cin >> K[i];
	}
	G.assign (K);
	G.dfs (1);
	debug (G.subtree);
	debug (G.is);
	debug (G.depth);
	cout << G.bfs () << '\n';
	return 0;
}
